#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL << 60;

int main(){
    ll N, M; 
    cin >> N >> M;
    vector<ll> p(M);
    vector<string> S(M);
    for (int i = 0; i < M; i++) cin >> p[i] >> S[i];

    vector<bool> check(N);
    for (int i = 0; i < N; i++) check[i] = false;

    vector<ll> wrn(N);
    ll cnt = 0, wrnout = 0;

    for (int i = 0; i < M; i++){
        if(S[i]=="AC"){
          check[p[i] - 1] = true;
        }
        else if(S[i]=="WA" && !check[p[i]-1]){
          wrn[p[i]-1]++;
        }
    }

    for (int i = 0; i < N; i++){
      if (check[i]) {
          cnt++;
          wrnout += wrn[i];
      }
    }
    cout << cnt << " " << wrnout << endl;
    return 0;
}