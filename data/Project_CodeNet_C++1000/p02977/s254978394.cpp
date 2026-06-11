#include <bits/stdc++.h>
#define rep(i, a, b) for(ll i = ll(a); i < ll(b); i++)
#define rer(i, a, b) for(ll i = ll(a) - 1; i >= ll(b); i--)
#define sz(v) (int)(v).size()
#define pb push_back
#define sc second
#define fr first
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
using namespace std;
typedef long long int ll;
typedef pair <int, int> P;

const ll MOD=1000000007;
ll n;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    rep(i,0,21){
        if(1LL<<i==n){
           cout <<"No"<<"\n";
            return 0;
        }
    }
    cout <<"Yes"<<"\n";
    rep(i,1,21){
        if(1LL<<i<n){
            cout <<(1LL<<i)<<" "<<(1LL<<(i-1))<<"\n";
        }
    }
    rep(i,1,21){
        rep(j,1,1LL<<i){
            if((1LL<<i)+j<=n){
                cout <<(1LL<<i)+j<<" "<<(1LL<<i)<<"\n";
            }
        }
    }
    cout <<n+1<<" "<<3<<"\n";
    cout <<n+2<<" "<<n+1<<"\n";
    rep(i,3,n+1){
        bool t=false;
        rep(j,0,21){
            if(1LL<<j==i){
                cout <<n+i<<" "<<n+i+1<<"\n";
                t=true;

            }
            if(1LL<<j==i+1){
                cout <<n+i<<" "<<1<<"\n";
                t=true;
            }
        }
        if(t) continue;
        ll s=i;
        rer(j,21,0){
            if(1LL<<j<i){
                if((1LL<<j&s)){
                    s-=1LL<<j;
                }
                else{
                    if(s==0){
                        s+=1LL<<(j+1);
                        cout <<n+i<<" "<<s<<"\n";
                        break;
                    }
                    s+=1LL<<j;
                    cout <<n+i<<" "<<s<<"\n";
                    break;
                }
            }
        }
    }
}