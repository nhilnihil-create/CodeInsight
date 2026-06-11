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
    ll H,W;
    cin >>H>>W;
    vector<string> S(H);
    vector<vector<ll>>RL(H,vector<ll>(W));
    vector<vector<ll>>UD(H,vector<ll>(W));
    rep(i,H){
        cin>>S[i];
    }

    rep(i,H){
        ll cnt=0;
        rep(j,W){
            if(S[i][j]=='.'){
                cnt++;
            }else{
                rep3(k,j-cnt,j){
                    RL[i][k]=cnt;
                }
                cnt=0;
            }
        }
        rep3(k,W-cnt,W){
            RL[i][k]=cnt;
        }

    }

    rep(i,W){
        ll cnt=0;
        rep(j,H){
            if(S[j][i]=='.'){
                cnt++;
            }else{
                rep3(k,j-cnt,j){
                    UD[k][i]=cnt;
                }
                cnt=0;
            }
        }
        rep3(k,H-cnt,H){
            UD[k][i]=cnt;
        }

    }
    ll ans =0;
    rep(i,H){
        rep(j,W){
            
           chmax(ans,RL[i][j]+UD[i][j]-1);
        }
        
    }


    cout<<ans<<endl;



    return 0;
    

}