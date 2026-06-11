#include<bits/stdc++.h>

using namespace std;

using ll = long long;



int main(){
  int N;
  string S;
  cin >> N >> S;
  
  if(S.size()%2!=0){
    cout << "No" << endl;
    return 0;
  }
  
  int cnt = 0;
  int l = (S.size()/2);
  for(int i=0; i<l; i++){
    if(S[i]==S[i+l]) cnt++;
  }
  
  if(cnt==l) cout << "Yes" << endl;
  else cout << "No" << endl;
    
  return 0;
}