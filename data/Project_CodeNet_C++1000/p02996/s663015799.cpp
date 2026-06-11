#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int mod = 1000000007;
using P = pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector<P> v;
    rep(i,n){
        int a,b;
        cin >> a >> b;
        v.emplace_back(b,a);
    }
    sort(v.begin(),v.end());
    ll now = 0;
    rep(i,n){
        now += v.at(i).second;
        if(now > v.at(i).first){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
    
}