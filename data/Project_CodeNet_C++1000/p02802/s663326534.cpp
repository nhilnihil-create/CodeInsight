#include<bits/stdc++.h>
#define MOD 1000000007
#define mp make_pair
#define ll long long
#define pb push_back
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define debug cout<<"Debugging.."<<endl
using namespace std;
int main()
{
	faster;
	int n,m;
	cin>>n>>m;
	int correct=0,pen=0;
	vector<bool> v(n,false);
	vector<int> cnt(n,0);
	while(m--)
	{
		int a;string b;
		cin>>a>>b;
		
		a--;
		if(v[a]==false)
		{
			if(b=="AC")
			{
				correct++;
				v[a]=true;
				pen+=cnt[a];
			}
			else
			cnt[a]++;
		}
		
	}
	cout<<correct<<" "<<pen;
}


