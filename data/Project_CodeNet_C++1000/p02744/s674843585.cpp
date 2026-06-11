#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int N;
string ALPHA = "abcdefghijklmn";

void solve(string s, int max_val, int n){
  if(n < N){
    for(int i = 0; i <= min(n,max_val+1); i++){
      solve(s + ALPHA[i], max(max_val, i), n+1);
    }
  } else { 
    cout << s << endl;
  }
}

int main(){
  cout << setprecision(10);
  cin >> N;
  string s = "";
  solve(s, 0,0);

}
