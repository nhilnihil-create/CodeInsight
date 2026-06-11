#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;

unsigned GetDigit(unsigned num){
  return to_string(num).length();
}

int main()
{
  int N;
  cin >> N;
  vector<vector<int>> cnt(9,vector<int>(9,0));
  FOR(i,1,N+1){
    int x = i%10;
    int y = i/pow(10,GetDigit(i)-1);
    if(x!=0&&y!=0){
      cnt[y-1][x-1]++;
    }
  }
  // FOR(i,1,10){
  //   if(i<=N){
  //     cnt[i-1][i-1]++;
  //   }
  // }
  // FOR(i,1,10){
  //   FOR(j,1,10){
  //     string s = "";
  //     s=to_string(i)+s+to_string(j);
  //     int x = stoi(s);
  //     if(x<=N){
  //       cnt[i-1][j-1]++;
  //     }
  //   }
  // }
  // REP(i,4){
  //   FOR(j,0,pow(10,i+1)){
  //     string S;
  //     S=to_string(j);
  //     REP(k,i+1-GetDigit(j)){
  //       S='0'+S;
  //     }
  //     FOR(k,1,10){
  //       FOR(l,1,10){
  //         string s = S;
  //         s=to_string(k)+s+to_string(l);
  //         int x = stoi(s);
  //         if(x<=N){
  //           cnt[k-1][l-1]++;
  //         }
  //       }
  //     }
  //   }
  // }

  ll ans = 0;
  REP(i,9){
    FOR(j,i,9){
      if(i!=j){
        ans+=2*cnt[i][j]*cnt[j][i];
      }else{
        ans+=cnt[i][j]*cnt[j][i];
      }
    }
  }
  // REP(i,9){
  //   REP(j,9){
  //     cout << cnt[i][j];
  //   }
  //   cout << endl;
  // }
  cout << ans << endl;
}