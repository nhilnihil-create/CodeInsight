#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  string S="",T="";
  char a,b; cin >> a >> b;

  for(int i = 0; i < a - '0'; i++){
    S += b;
  }
  for(int i = 0; i < b - '0'; i++){
    T += a;
  }

  cout << (S < T ? S : T) << endl;
}
