#include<bits/stdc++.h>
 
#define rep(i,n) for(ll i = 0;i < n;++i)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
typedef pair<int,int> P;
 
const int INF = 1001001001;
const long double PI = (acos(-1));
const int mod = 1e9+7;
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s[3] = {"Sunny","Cloudy","Rainy"};
    string a;
    cin >> a;
    rep(i,3){
        if(a == s[i]){
          if(i == 2) {
            cout << s[0] << endl;
            return 0;
          }
            cout << s[i+1] << endl;
            return 0;
        }
    }

    cout << endl;
    return 0;
}
