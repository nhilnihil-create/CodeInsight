#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

int main(){
  int N,K,R,S,P;
  string T;
  cin >> N >> K;
  cin >> R >> S >> P;
  cin >> T;
  ll ans = 0;
  ll count[T.length()];
  for(int i=0;i<K;i++){
    count[i]=0;
    if(T[i]=='r') ans += P;
    if(T[i]=='s') ans += R;
    if(T[i]=='p') ans += S;
  }
  for(int i=K;i<T.length();i++){
    count[i]=0;
    if(T[i]!=T[i-K]){
      if(T[i]=='r') ans += P;
      if(T[i]=='s') ans += R;
      if(T[i]=='p') ans += S;
      count[i] = 0;
    }else if(count[i-K]%2!=0){
      if(T[i]=='r') ans += P;
      if(T[i]=='s') ans += R;
      if(T[i]=='p') ans += S;
      count[i] = count[i-K]+1 ;
    }else{
      count[i] = count[i-K]+1 ;
    }
  }
  cout << ans << endl;
}
