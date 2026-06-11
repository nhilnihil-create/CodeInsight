#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

int main(){
    int X; cin >> X;
    int ans = 0;
    if(X >= 1800)ans = 1;
    else if(X >= 1600) ans = 2;
    else if(X >= 1400) ans = 3;
    else if(X >= 1200) ans = 4;
    else if(X >= 1000) ans = 5;
    else if(X >= 800) ans = 6;
    else if(X >= 600) ans = 7;
    else if(X >= 400) ans = 8;
    cout << ans << endl;
} 