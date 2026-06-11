#include<bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using pint = pair<int,int>;
using pll = pair<ll,ll>;
using Graph = vector<vector<int>>;

int main(){
    int N,K,C; cin>>N>>K>>C;
    string S; cin>>S;

    //前から貪欲
    vector<int> L,R;
    int now = 0;
    while(now<N){
        if(S[now]=='o'){
            L.push_back(now+1);
            now += C;
        }
        now++;
    }
    
    now = N-1;
    while(now>=0){
        if(S[now]=='o'){
            R.push_back(now+1);
            now -= C;
        }
        now--;
    }
    reverse(R.begin(),R.end());
    if(L.size()==K&&R.size()==K){
        rep(i,K)if(L[i]==R[i])cout<<L[i]<<endl;
    }
}
