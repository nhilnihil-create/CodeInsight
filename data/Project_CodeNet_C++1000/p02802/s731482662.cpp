#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define REP(i,n) for(int i=1;i<=n;i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(V) V.begin(), V.end()
#define PB push_back
using namespace std;
typedef long long ll;

int main() {
    int n,m;
    cin >> n >>m;
    vector<int>wa(n);
    vector<bool>flag(n);
    int pena = 0;
    int cnt = 0;

    rep(i,m){
        int p;
        string s;
        cin >> p >> s;
        if(s == "WA" && flag[p] == false) {
            wa[p]++;
        }
        if(s == "AC" && flag[p] == false){
            cnt++;
            pena += wa[p];
            flag[p] = true;
        } 
    }
    cout << cnt << " "<< pena <<endl;
}