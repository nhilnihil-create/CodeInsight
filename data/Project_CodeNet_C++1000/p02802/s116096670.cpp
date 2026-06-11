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
    ll N,M;
    cin >>N>>M;
    map<ll,ll> A;
    map<ll,ll> W;
    ll ac = 0,wa = 0;
    rep(i,M){
        ll a;
        string b;
        cin >>a>>b;
        if(b == "AC"){
            if(A[a] == 0 ){
                ac++;
                A[a] = 1;
                wa += W[a];
            }
        }else{
            if(A[a] == 0 ){
                W[a]++;
                
            }
        }

    }
    cout << ac<<" "<<wa << endl;


    return 0;
    

}