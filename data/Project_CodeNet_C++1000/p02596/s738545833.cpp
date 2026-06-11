#include<bits/stdc++.h>
using namespace std;
const unsigned int M = 1000000007;
int main(){
  long long a;
  cin >> a;
  vector<long long> b(1000000);
  b[0] = 7%a;
  if(b[0]==0){
     cout << 1 << endl;
     return 0;
  }
  for(int i= 1;i<=1000000;i++){
   b[i] = (10*b[i-1]+7)%a;
  if(b[i]==0){
     cout << i+1 << endl;
     return 0;
  }
  }
  cout << -1 << endl;
 return 0;
}