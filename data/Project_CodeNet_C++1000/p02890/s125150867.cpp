#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0; i < (ll)(n); i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1LL << 60;
int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n){
        int x;
        cin >> x;
        a[x-1]++;
    }
    sort(a.begin(),a.end());
    vector<int> s(n);
    s[0] = a[0];
    rep(i,n-1) s[i+1] = s[i] + a[i+1];

    for(int k=1; k<=n; k++){
        int l=0, r=n/k+1; //二分探索は半開区間がいい
        while(l+1<r){
            int x = (l+r)/2; //x回取れるならl=x, 取れないならr=x;
            bool ok = [&](int c){
                int i = lower_bound(a.begin(),a.end(),c) - a.begin(); //このindexからはc以上
                int sm;
                if(i) sm = s[i-1] + (n-i)*c;
                else sm = n*c;
                return sm >= k*c;
            }(x);
            if(ok) l=x; else r=x;
        }
        cout << l << endl;
    }
    return 0;
}