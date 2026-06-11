#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  string S; cin >> S;

  for(int i = 0; i < S.size(); i++){
    char c = S[i];
    if(i % 2 == 0){
      if(c == 'R' || c == 'D' || c == 'U'){
        continue;
      } else {
        cout << "No" << endl;
        return 0;
      }
    } else { 
      if(c == 'L' || c == 'D' || c == 'U'){
        continue;
      } else {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
}
