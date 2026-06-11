#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int z_algorithm(string S){
  vector<int> A(S.size(),0);
  // zアルゴリズム 
  A[0] = S.size();
  int i = 1, j = 0;
  while (i < S.size()){
    while (i+j < S.size() && S[j] == S[i+j]) ++j; // 右向きにjを伸ばしていく
    A[i] = j;
    if (j == 0) { ++i; continue;}
    int k = 1;
    while (i+k < S.size() && k+A[k] < j) A[i+k] = A[k], ++k; // i~j間にkを走らせる
    i += k; j -= k;
  }

  int ret = 0; 
  for(int i = 0; i < S.size(); i++){
    int tmp = min(i, A[i]);
    ret = max(tmp, ret);
  }
  return ret;
}

int main(){
  cout << setprecision(10);

  int N; cin >> N;
  string S; cin >> S;

  int ret = 0;
  for(int l = 0; l < N; l++){
    string x = S.substr(l);
    int tmp = z_algorithm(x);
    ret = max(ret, tmp);
  }
  cout << ret << endl;
}
