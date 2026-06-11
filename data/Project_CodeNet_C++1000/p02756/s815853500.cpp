#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;

ll INF = 1e+18;
int iINF = 1e9;

int 
main()
{
  string S; cin >> S;
  int Q; cin >> Q;
  bool flag = true;
  string front = "";

  rep(i, 0, Q){
    int tmp; cin >> tmp;
    if(tmp == 1){
      flag = !flag;
    } else {
      int F; cin >> F;
      string add; cin >> add;
      if(F == 1){
        if(flag) front += add;
        else S += add;
      } else {
        if(flag) S += add;
        else front += add;
      }
    }
  }

  if(flag){
    reverse(front.begin(), front.end());
    cout << front + S << endl;
  } else {
    reverse(S.begin(), S.end());
    cout << S + front << endl;
  }

}