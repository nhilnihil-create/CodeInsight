#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll=long long;

int main(){
  string S, T;
  int max=0, a, b, count;
  cin >> S >> T;
  a=S.size();
  b=T.size();
  
  for(int i=0; i<a-b+1; i++){
    count=0; 
    for(int j=0; j<b; j++){
        if(S.at(i+j)==T.at(j)) count++;
    }
    if(count>max) max=count;
  }
  
  cout << b-max << endl;
  
}
    
