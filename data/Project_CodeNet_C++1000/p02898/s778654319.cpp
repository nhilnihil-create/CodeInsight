//MISHON69
//DATE:6/22/2020
#include<bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int n,k;
  cin>>n>>k;
  int a[n];
  FOR(i,n)
  cin>>a[i];
  int count=0;
  FOR(i,n){
     if(a[i]>=k)
     count++;
  }
  cout<<count<<endl;
}  
