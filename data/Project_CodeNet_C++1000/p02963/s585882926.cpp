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

int main(){

    ll s; cin >> s;
    ll k = (s-1)/1000000000+1;
    cout << 0 sp 0 sp 1000000000 sp 1000000000*k-s sp 1 sp k << endl;

    return 0;

}