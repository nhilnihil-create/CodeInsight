#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define sp <<" "<<
#define cst(x) cout<<fixed<<setprecision(x)
#define pi 3.14159265358979
#define mod 1000000007
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vl = vector<ll>;
using Graphi = vector<vi>;
using que_a = priority_queue<int, vector<int>, greater<int> >;
using que_d = priority_queue<int>;
using pint = pair<int,int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
struct edge {
    int to; 
    int weight;
    edge(int t, int w) : to(t),weight(w) {}
};

vector<ll> a;
int n;

ll culc(){

    ll ans = 0;
    ll loop = 1;

    rep(i,60){
        if(i != 0){
            loop *= 2;
            loop %= mod;
        }
        ll cnt_one = 0;
        ll cnt_zero = 0;
        rep(j,n){
            if(a.at(j) >> i & 1) cnt_one++;
            else cnt_zero++;
        }
        ll temp = (cnt_one * cnt_zero)%mod;
        temp = (temp*loop)%mod;
       
        ans += temp;
        ans %= mod;
    }

    return ans;

}

int main(){

    cin >> n;
    a.resize(n);
    rep(i,n) cin >> a.at(i);

    cout << culc() << endl;
    return 0;

}