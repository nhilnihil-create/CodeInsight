#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
int main(){
    int n,d,a;
    cin>>n>>d>>a;
    vector<pair<int,int>> p(n);
    for(auto& e:p)cin>>e.first>>e.second;
    sort(p.begin(),p.end());
    vector<int> s(n+1);
	int r=0;
    long long ans=0;
    rep(i,n){
        p[i].second-=s[i];
        while(r<n&&p[r].first<=p[i].first+2*d)++r;
        if(p[i].second>0){
            int num=(p[i].second+a-1)/a;
            ans+=num;
            s[i]+=num*a;
            s[r]-=num*a;
        }
        s[i+1]+=s[i];
    }
    cout<<ans<<endl;
    return 0;
}
