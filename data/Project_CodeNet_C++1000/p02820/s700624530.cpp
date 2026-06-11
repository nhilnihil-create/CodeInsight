#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  int n, k; cin >> n >> k;
  int R, S, P; cin >> R >> S >> P;
  string t; cin >> t;
  int ans = 0;

  vector<string> mods(k);
  rep(i,n){
    mods[(i+1)%k] += t[i];
    switch(t[i]){
      case 'r': ans+=P; break;
      case 'p': ans+=S; break;
      case 's': ans+=R; break;
    }
    //cout << ans << endl;
  }



  /*rep(i,k){
    cout << mods[i] << endl;
  }*/

  rep(i,k){
    int streak =1;
    char now;
    rep(j,mods[i].size()-1){
      if(mods[i][j] == mods[i][j+1]){
        streak++;
        now = mods[i][j];
        //cout << "streak: " << streak << "  hand: " << mods[i][j] << endl;
      }
      else{
        //cout << "else!!!  " << "streak: " << streak << "  hand: " << mods[i][j] << endl;
        switch(now){
          case 'r': ans-=P*(streak/2); break;
          case 'p': ans-=S*(streak/2); break;
          case 's': ans-=R*(streak/2); break;
        }
        streak = 1;
      }
      if(j == mods[i].size()-2){
        //cout << "end!!!   "  << "streak: " << streak << "  hand: " << mods[i][j] << endl;
        switch(now){
          case 'r': ans-=P*(streak/2); break;
          case 'p': ans-=S*(streak/2); break;
          case 's': ans-=R*(streak/2); break;
        }
        streak = 1;
      }
    }
  }
  cout << ans << endl;
}
