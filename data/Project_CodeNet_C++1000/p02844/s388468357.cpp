#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,f,n) for(int i=f; i<(n); i++)
int main()
{
  ll ans = 0, n;
  string s;
  cin >> n;
  cin >> s;

  
  REP(i,0,10){
    int f1 = s.find_first_of(i+'0');
    if(f1 != -1){
      string s2 = s.substr(f1+1);
      REP(i2,0,10){
        int f2 = s2.find_first_of(i2+'0');
        if(f2 !=-1){
          string s3 = s2.substr(f2+1);
          REP(i3,0,10){
            int f3 = s3.find_first_of(i3+'0');
            if(f3 !=-1){
              ans++;
            }
          }
        }
      }
    }
  }
  cout << ans << endl;

  //--debug : end_stoper
  string end_stoper; cin >> end_stoper;

  return 0;
}