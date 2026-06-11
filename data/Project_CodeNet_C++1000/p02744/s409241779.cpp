#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int N;
string ALPHA = "abcdefghijklmn";

void solve(string s, char c){
  if(s.size() < N){
    for(char i = 'a'; i <= c+1; i++){
      solve(s + i, (i == c+1 ? (c+1) : c));
    }
  } else { 
    cout << s << endl;
  }
}

int main(){
  cout << setprecision(10);
  cin >> N;
  string s = "";
  solve("a", 'a');

  cerr  << (char)('a' + 1) << endl;

}
