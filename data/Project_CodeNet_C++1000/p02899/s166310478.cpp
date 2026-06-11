#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k,f=0;
  cin >> n;
  map<int,int> a;
  for(int i=1;i<=n;i++){
    cin >> k;
    a[k]=i;
  }
  for(int i=1;i<=n;i++)cout << (i-1?" ":"") << a[i] ;
  cout << endl;
}