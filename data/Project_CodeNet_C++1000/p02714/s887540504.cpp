#include <iostream>
#include <string>

using namespace std;

int main(void){
  int N;
  string S;
  long long r, g, b, ans;

  r = g = b = 0;

  cin >> N;
  cin >> S;

  for(int i=0; i<N; i++){
    if(S[i]=='R') r++;
    if(S[i]=='G') g++;
    if(S[i]=='B') b++;
  }
  ans = r * g * b;

  for(int k=2; k<N; k++){
    for(int i=0; i<k-1; i++){
      if((i+k)%2==0){
        int j = (i + k) / 2;
        if(S[i]!=S[j] && S[j]!=S[k] && S[i]!=S[k]) ans--;
      }
    }
  }

  cout << ans << endl;
}