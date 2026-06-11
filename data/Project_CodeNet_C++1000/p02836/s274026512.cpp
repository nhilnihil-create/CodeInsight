#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef pair<int, int> pii;  // pair<int, int> に pii という別名を付ける
typedef long long ll;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string S;
  cin >> S;
  int N = S.size();
  int count = 0;
  for (int i = 0; i < ceil(N/2.0); i++){
    if(S.at(i) != S.at(N-1-i)){
      count ++;
    }
  }
  cout << count << endl;
}