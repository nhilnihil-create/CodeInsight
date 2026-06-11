#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i= (a); i < (b); ++i)
typedef long long ll;
typedef pair<int,int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
int main() { string S;
  cin >> S;
  if(S[0]==S[1]&&S[1]==S[2]){
    puts("No");
    return 0;
  }
  if(S[0]==S[1]){
    if(S[2]==S[3]){
      puts("Yes");
      return 0;
    }    
  }
  if(S[0]==S[2]){
    if(S[1]==S[3]){
      puts("Yes");
      return 0;
    }
  }
  if(S[0]==S[3]){
    if(S[1]==S[2]){
      puts("Yes");
      return 0;
    }
  }

  puts("No");
}