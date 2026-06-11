#include <bits/stdc++.h>
using  namespace std;
typedef long long ll;
#define RAP(i, n) for(ll i=0;i<(n);i++)
#define FOR(i, a, b) for(ll i=(a);i<(b);i++)
#define MFOR(i, a, b) for(ll i=(a);i>=(b);i--)

int main(){
    ll h, w, check, ans=-1, num;
    cin >> h >> w;
    char S[h][w];
    vector<vector<ll>> w_num(h), h_num(h);
    RAP(i, h){
      w_num[i].resize(w, 0);
      h_num[i].resize(w, 0);
    }
    RAP(i, h){
        RAP(j, w){
            cin >> S[i][j];
        }
    }
    RAP(i, h){
        RAP(j, w){
          check = j;
          num = -1;
          while(check<w && S[i][check]!='#'){
            check++;
            num++;
          }
          for(j;j<check;j++){
            w_num[i][j] = num;
          }
        }
    }
    RAP(i, w){
        RAP(j, h){
          check = j;
          num = 0;
          while(check<h && S[check][i]!='#'){
            check++;
            num++;
          }
          for(j;j<check;j++){
            h_num[j][i] = num;
          }
        }
    }
    RAP(i, h){
        RAP(j, w){
          ans = max(ans, w_num[i][j] + h_num[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}
