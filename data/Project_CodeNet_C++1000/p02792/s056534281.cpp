#include<bits/stdc++.h>
using namespace std;
#define ll long long

int max(int n){
  while(n>=10){
    n /= 10;
  }
  return n;
}

int main(){
  int n,i,j;
  cin >> n;
  vector<vector<int>> a(10,vector<int>(10,0));
  for(i=1;i<=n;i++){
    a.at(max(i)).at(i%10)++;
  }
  
  int s=0;
  for(i=0;i<10;i++){
    for(j=0;j<10;j++){
      s += a.at(i).at(j)*a.at(j).at(i);
    }
  }
  
  cout << s << endl;
}