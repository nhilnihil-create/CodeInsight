#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair< ll, ll > Pi;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<=(n);i++)
#define rep3(i,i0,n) for(int i=i0;i<(n);i++)
#define pb push_back
#define mod 1000000007
const ll INF = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}
#define all(x) x.begin(), x.end()
#define mp make_pair
bool compare(Pi a, Pi b) {
    if(a.first != b.first){
        return a.first < b.first;
        
    }else{
        return a.second < b.second;
    }
}


bool In_map(ll y,ll x,ll h,ll w){
    if(y<0 || x<0 || y>=h || x>=w){
        return 0;
    }else{
        return 1;
    }
}
const vector<ll> dx{1,0,-1,0};
const vector<ll> dy{0,1,0,-1};


int main() {
    ll X,Y,A,B,C;
    cin >>X>>Y>>A>>B>>C;
    vector<ll>p(A);
    vector<ll>q(B);
    vector<ll>r(C);

    rep(i,A) cin>>p[i];
    rep(i,B) cin>>q[i];
    rep(i,C) cin>>r[i];

    sort(all(p));
    sort(all(q));
    sort(all(r));
    reverse(all(p));
    reverse(all(q));
    reverse(all(r));
    ll cnta=0;
    ll cntb=0;
    ll cntc=0;
    while(1){
        if(cntc==C) break;
        if(X-1-cnta>=0 && Y-1-cntb>=0){
            if(p[X-1-cnta]<q[Y-1-cntb]){
                if(p[X-1-cnta]<r[cntc]){
                    p[X-1-cnta] = r[cntc];
                    cnta++;
                    cntc++; 
                }else{
                    break;
                }
            }else{
                if(q[Y-1-cntb]<r[cntc]){
                    q[Y-1-cntb] = r[cntc]; 
                    cntb++;
                    cntc++;
                }else{
                    break;
                }
            }
        }else if(X-1-cnta>=0){
            if(p[X-1-cnta]<r[cntc]){
                p[X-1-cnta] = r[cntc];
                cnta++;
                cntc++; 
            }else{
                break;
            }
        }else if(Y-1-cntb>=0){
            if(q[Y-1-cntb]<r[cntc]){
                q[Y-1-cntb] = r[cntc]; 
                cntb++;
                cntc++;
            }else{
                break;
            }
        }else{
            break;
        }

    }
    ll ans=0;
    rep(i,X){
        ans+=p[i];
    }

    rep(i,Y){
        ans+=q[i];
    }
    cout << ans << endl;


    return 0;
    

}