#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

int main(){
  string S;
  int N;
  cin >> N;
  cin >> S;
  for(int i=0;i<S.length();i++){
    if('Z'-S[i]<N) cout << char(S[i]+N-26);
    else cout << char(S[i]+N);
  }
  cout << endl;
}
