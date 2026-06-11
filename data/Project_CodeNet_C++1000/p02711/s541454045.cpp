#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  string S; cin >> S;
  for(auto c : S){
    if(c - '0' == 7){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
