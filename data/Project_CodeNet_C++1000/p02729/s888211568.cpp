#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n,m;
  cin >> n >> m;
  int count=0;
  if(n<=1) cout << (m*(m-1))/2 << endl;
  else if(m<=1) cout << (n*(n-1))/2 << endl;
  else{
    count += (n*(n-1))/2+(m*(m-1))/2;
    cout << count << endl;
  }  
  return 0;
}