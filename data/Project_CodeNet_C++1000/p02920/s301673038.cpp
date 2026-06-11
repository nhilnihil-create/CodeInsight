#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cstdio>
#include<cmath>
#include<map>
#include<set>
using namespace std;
using lint=long long;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
int MOD=1000000007;
signed main(){
    int n;cin>>n;
    multiset<int> rem;
    int mx=0;
    int d=(1ull<<n);
    rep(i,d){
        int buf;cin>>buf;
        rem.insert(buf);
        mx=max(mx,buf);
    }
    multiset<int> bef;
    bef.insert(mx);
    if(rem.count(mx)!=1){
        cout<<"No"<<endl;
        return 0;
    }
    rem.erase(rem.find(mx));
    int cur=1;

    rep(i,n){
        vector<int> use;
        for(const auto& it:bef){
            auto it2=rem.lower_bound(it);
            if(*it2==it||true){
                if(it2!=rem.begin())--it2;
                else{
                    if(*it2>=it){
                        cout<<"No"<<endl;
                        return 0;
                    }
                }
            }
            use.push_back(*it2);
            rem.erase(rem.find(*it2));
        }
        for(const auto& val:use){
            bef.insert(val);
        }
        cur*=2;
    }
    for(auto it:rem){
        cout<<it<<endl;
    }
    cout<<"Yes"<<endl;
    return 0;
}