#include <bits/stdc++.h>
#define mk make_pair
#define fs first
#define sc second
using namespace std;
typedef long long ll;
typedef long double ld;
ll a[100010];
map<ll, ll> mp[2];
ll cnt[66];
int main(){
    int n;
    while(cin>>n){
        ll ans=0;
        for(int i=0; i<60; ++i){
            cnt[i]=0;
        }
        for(int i=0; i<n; ++i){
            scanf("%lld",a+i);
            for(int j=0; j<60; ++j){
                if(a[i]&(1ll<<j)){
                    ++cnt[j];
                }
            }
        }
        ans=0;
        ll tmp;
        for(int i=59; i>=0; --i){
            if(cnt[i]%2){
                ans+=(1ll<<i);
                for(int j=0; j<n; ++j){
                    a[j]&=~(1ll<<i);
                }
            }
        }
        int x=0;
        for(int i=59; i>=0; --i){
            int tmp=-1, tmp1=0;
            for(int j=0; j<x; ++j){
                if(a[j]&(1ll<<i))
                    ++tmp1;
            }
            for(int j=x; j<n; ++j){
                if(a[j]&(1ll<<i)){
                    tmp=j;
                    break;
                }
            }
            if(tmp1%2||tmp!=-1)
                ans+=2*(1ll<<i);
            if(tmp==-1)
                continue;
            swap(a[x], a[tmp]);
            for(int j=0; j<n; ++j){
                if(x==j)
                    continue;
                if(a[j]&(1ll<<i)){
                    a[j]^=a[x];
                }
            }
            ++x;
        }
        cout<<ans<<endl;

    }
  return 0;
}


