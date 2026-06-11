#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define sp <<" "<<
#define cst(x) cout<<fixed<<setprecision(x)
#define pi 3.14159265359
#define mod 1000000007
struct edge {
    int to; 
    int weight;
    edge(int t, int w) : to(t),weight(w) {}
};
using namespace std;
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;
using que_a = priority_queue<int, vector<int>, greater<int> >;
using que_d = priority_queue<int>;
using pint = pair<int,int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main(){

    int n; cin >> n;
    vector<pair<int,int>> ro(n);
    rep(i,n){
        int x,l; cin >> x >> l;
        ro.at(i) = make_pair(x+l,x-l);
    }
    sort(all(ro));
    int cnt;
    int lim ;
    lim = ro.at(0).first;
    cnt = 1;
    for(int i = 1; i < n; i++){
        if(ro.at(i).second >= lim){
            lim = ro.at(i).first;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
