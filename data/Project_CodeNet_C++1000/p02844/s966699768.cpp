#include <bits/stdc++.h>
using namespace std;

#define printl(s) cout << s << endl;
#define print(s) cout << s << endl; return 0;
#define yes cout << "Yes" << endl; return 0;
#define no cout << "No" << endl; return 0;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i,n) for (int i = 1; i < (n)+1; ++i)
using ll = long long;

const ll modseed = pow(10,9) + 7;

template <typename T>
vector<T> getValues(ll num){
    vector<T> values(num);
    for(ll i=0;i<num;i++){
        cin >> values.at(i);
    }
    return values;
}

string S;
ll A,B,C,K,N,X,Y,cnt;

int main(){
  cin >> N >> S;
  rep(i,1000){
    int idx=0;
    vector<int> tgt = {i/100,(i/10)%10,i%10};
    rep(j,N){
      if(S.at(j)==('0' + tgt.at(idx))){
        idx++;
        if(idx==3){
          break;
        }
      }
    }
    if(idx==3) cnt++;
  }
  print(cnt);
}
