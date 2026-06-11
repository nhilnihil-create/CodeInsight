#include <bits/stdc++.h>
using namespace std;
#define	rep(i,n)	for(int i=0;i<n;i++)
int main(){
  int n;	cin >> n;
  vector<int>	d(n);
  rep(i,n)	cin >> d[i];
  sort(d.begin(),d.end());
  
  if(d[n/2]==d[n/2-1])	cout << 0;
  else	cout << d[n/2]-d[n/2-1];
}