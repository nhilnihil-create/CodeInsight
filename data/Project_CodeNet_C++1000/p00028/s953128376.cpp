
#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int>PAIR;
 
bool cmp(const PAIR&left,const PAIR&right){     //Õâ¶ùÓÐ¸Ä¶¯ 
	
		return left.second == right.second ? left.first < right.first : left.second > right.second;
	
};
  
int main()
{
	map<int,int>m;
	int a,max;
	while(~scanf("%d",&a))
		m[a]++;
	vector<PAIR>v(m.begin(),m.end());
	sort(v.begin(),v.end(),cmp);
	max=v[0].second;
	for(int i=0;i!=(int)v.size();++i)
		if(v[i].second==max)
			cout<<v[i].first<<endl;
		else 
			break;
	return 0;
}

