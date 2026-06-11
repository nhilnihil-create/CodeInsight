#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
  int N;
  cin >> N;
  
  vector<int>H(N);
  for(int i = 0; i < N; i++)cin >> H[i];
  
  reverse(H.begin(),H.end());
  
  for(int i = 0; i < N; i++){
    if(i == 0)continue;
    if(H[i]-H[i-1] == 1)H[i]--;
    else if(H[i] <= H[i-1])continue;
    else{
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}