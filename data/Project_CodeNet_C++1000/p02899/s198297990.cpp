#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
int m,n; 
struct SY
{
	int a,b;
}sy[100005];
int cmp(SY a,SY b)
{
	return a.a<b.a;
}
int main()
{
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    cin>>m;
    for(int i=1;i<=m;++i)
    {
    	cin>>sy[i].a;
    	sy[i].b=i;
	}
	sort(sy+1,sy+m+1,cmp);
	for(int i=1;i<=m;++i) cout<<sy[i].b<<" ";
	return 0;
}