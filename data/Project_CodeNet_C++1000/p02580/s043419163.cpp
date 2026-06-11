#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	int H,W,M;
	cin>>H>>W>>M;
	map<int,int> height;
	map<int,int> width;
	vector<vector<int>> target_h(H);
	vector<vector<int>> target_w(W);
	int max_h=-1;
	int max_w=-1;
	rep(i,M)
	{
		int h,w;
		cin>>h>>w;
		h--;
		w--;
		target_h[h].push_back(w);
		target_w[w].push_back(h);
		height[h]++;
		width[w]++;
		if(height[max_h]<height[h])
		{
			max_h=h;
		}
		if(width[max_w]<width[w])
		{
			max_w=w;
		}
	}
	map<int,bool> seen_w;
	for(auto p : height)
	{
		if(height[max_h]==p.second)
		{
			for(int v : target_h[max_h])
			{
				seen_w[v]=true;
			}
		}
	}	
	bool is_max=true;
	for(auto p : width)
	{
		if(width[max_w]==p.second&&!seen_w[p.first])
		{
			is_max=false;
			break;
		}
	}
	map<int,bool> seen_h;
	for(auto p : width)
	{
		if(width[max_w]==p.second)
		{
			for(int v : target_w[max_w])
			{
				seen_h[v]=true;
			}
		}
	}
	for(auto p : height)
	{
		if(height[max_h]==p.second&&!seen_h[p.first])
		{
			is_max=false;
			break;
		}
	}
	if(is_max)
	{
		cout<<height[max_h]+width[max_w]-1<<endl;
	}
	else
	{
		cout<<height[max_h]+width[max_w]<<endl;
	}
	return 0;
}
