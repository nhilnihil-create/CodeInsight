#include<bits/stdc++.h>
 
#define rep(i,n) for(ll i = 0;i < n;++i)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
typedef pair<int,int> P;
 
const int INF = 1001001001;
const long double PI = (acos(-1));
const int mod = 1e9+7;

ll f(int y,int m,int d){
    ll res;
    res = (365*y) + (y/4) - (y/100) + (y/400) + (306*(m+1)/10) + d -429;
    return res;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<double> a(n);
    rep(i,n){
        cin >> a[i];
    }
    rep(i,n){
        a[i] = 1/a[i]; 
    }
    double sum=0;
    rep(i,n){
        sum += a[i];
    }
    sum = 1/sum;
    cout << fixed << setprecision(10) << sum << endl;

    return 0;
}
