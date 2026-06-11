#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<=(n);i++)
#define rep3(i,i0,n) for(int i=i0;i<(n);i++)
#define pb push_back
#define mod 1000000007
#define INF 200000000000
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}
#define all(x) x.begin(), x.end()

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first){
        return a.first < b.first;
        
    }else{
        return a.second < b.second;
    }
}
// 入力



int main() {
    ll N;
    cin >>N;
    vector<vector<pair<ll,ll>>> xy(N);
    
    rep(i,N){
        ll A;
        cin >> A;
        rep(j,A){
            ll x,y;
            cin >> x>>y;
            xy[i].pb(make_pair(x-1,y));
        }

    }
    ll max = 0;
    rep(bit,1<<N){
        vector<ll> S;
        vector<ll> S2;
        rep(i,N){
            if(bit&(1<<i)){
                S.pb(i);
                S2.pb(1);
            }else{
                S2.pb(0);
            }
        }
        bool flag = 0;
        rep(i,S.size()){
            rep(j,xy[S[i]].size()){
                if(xy[S[i]][j].second == 1 && S2[xy[S[i]][j].first] == 0){
                    flag =1;
                    //cout<<"A"<<endl;
                    break;
                }
                if(xy[S[i]][j].second == 0 && S2[xy[S[i]][j].first] == 1){
                    flag =1;
                    //cout<<"B"<<endl;
                    break;
                }
                
            }
            if(flag) break;
            if(i == S.size()-1){
                if(S.size() > max){
                    max = S.size();
                }
                
            }
        }
        
    }
    cout << max << endl;


    return 0;
    

}