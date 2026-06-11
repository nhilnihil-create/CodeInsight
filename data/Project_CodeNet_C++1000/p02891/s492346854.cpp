#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
int main() {
    string s;
    ll k , ans = 0 , tmp = 0;
    cin >> s >> k;
    ll n = s.size();
    ll a = 1;
    for(int i = 0; i < n; i++) {
        if(s[i] == s[i + 1]){
            a++;
        }
        else{
          	if(a == 1) a--;
            ans += a / 2;
          	tmp++;
          	a = 1;
        }
    }
  	if(tmp == 1){
          cout << n * k / 2 << endl;
    }
    else if(s.front() == s.back()) {
      	ll M = 0, N = 0;
        for(int i = 0; i < n; i++) {
            M++;
            if(s[i] != s[i + 1]) break;
        }
        for(int i = n - 1; i >= 0; i--) {
            N++;
            if(s[i] != s[i - 1]) break;
        }
        cout<<ans * k - (k - 1) * ((M / 2) + (N / 2) - (M + N) / 2) << endl;;
    }
  	else{
          cout << ans * k<<endl;
      }
}
