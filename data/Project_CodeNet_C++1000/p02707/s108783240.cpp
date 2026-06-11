#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(){
  int n;
  cin >> n;
  int a[n-1];
  rep(i,n-1)cin >> a[i];

  int leader[n];
  memset(leader,0,sizeof(leader));
  rep(i,n-1)leader[a[i]-1]++;

  rep(i,n)cout << leader[i] << endl;
}