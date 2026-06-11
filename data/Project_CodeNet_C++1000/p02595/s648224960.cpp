#include <bits/stdc++.h>
using namespace std;

#define printl(s) cout << s << endl;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N, D;
    cin >> N >> D;

    int ans = 0;
    rep(i,N){
      double x,y;
      cin >> x >> y;
      double dist = sqrt((x*x+y*y));
      if(dist<=D){
        ans++;
      }
    }
    printl(ans);
}
