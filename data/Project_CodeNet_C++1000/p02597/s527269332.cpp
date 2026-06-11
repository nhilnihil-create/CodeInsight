#include <iostream>
using namespace std;

int main(){
  int N;
  string S;
  cin >> N;
  cin >> S;
  
  char c[200001];
  int white=0;
  for (int i=1; i<=N; i++){
    c[i]=S[i-1];
    if (c[i] == 'W'){
      white++;
    }
  }
  
  int ans=0;
  for (int i=0; i<white; i++){
    if (c[N-i] == 'R'){
      ans++;
    }
  }
  
  cout << ans << endl;
  
  return 0;
}