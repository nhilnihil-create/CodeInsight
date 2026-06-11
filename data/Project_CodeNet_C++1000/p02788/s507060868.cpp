#include<bits/stdc++.h>
using namespace std;
long long pre[200007];
int main(){
	ios::sync_with_stdio(false);//关同步 
	long long n,d,a;
	cin>>n>>d>>a;
	vector<pair<long long,long long> >v;
	for(int i=1;i<=n;++i){
		long long x,y;
		cin>>x>>y;
		long long z=(y-1)/a+1;
        v.push_back({x,z});
    }
    sort(v.begin(),v.end());
    long long ans=0;
    long long sum=0;
    int r=1;//打不到的最近范围 
    for(int i=0;i<n;++i){
		while(r<n&&v[r].first<=v[i].first+2*d)
			++r;
		sum-=pre[i];//sum为当前位置已经预先承受的伤害总量
		v[i].second-=sum;
		if(v[i].second<=0)
			continue;
		sum+=v[i].second;//累计伤害 
		pre[r]+=v[i].second;//r位置以前承受的伤害总量 
		ans+=v[i].second;
	}
	cout<<ans;
	return 0;
}