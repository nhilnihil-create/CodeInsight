#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int n;
    string s;
    cin >> n >> s;
    int a = 0, b = 0;
    rep(i,n) if(s[i] == 'R') a++;
    int ans = a;
    rep(i,n){
        if(s[i] == 'R') a--;
        else b++;
        ans = min(ans, max(a, b));
    }
    cout << ans << endl;
}