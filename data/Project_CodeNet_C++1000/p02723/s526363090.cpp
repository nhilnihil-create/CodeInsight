#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  string S; cin >> S;

  if(S[2] == S[3] && S[4]==S[5]){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
