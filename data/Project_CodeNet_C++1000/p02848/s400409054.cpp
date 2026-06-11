#include<bits/stdc++.h>
using namespace std;

int main(){
  long long int N ,ans = 0 ;
  string S ;
  cin >> N >> S;
  for(long long int i = 0; i < S.size(); i++){
    if(char(S[i] + N) <= 'Z') cout << char(S[i] + N) ;
    else cout << char(S[i] + N - 26);
  }
}
