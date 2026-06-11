#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  string S,T; cin >> S >>T ;
  if(S.size() + 1 != T.size()){
    cout << "No" << endl;
    return 0;
  }

  for(int i = 0; i < S.size(); i++){
    if(S[i] != T[i]){
      cout << "No" << endl;
      return 0;
    }

  }
  cout << "Yes" << endl;
}
