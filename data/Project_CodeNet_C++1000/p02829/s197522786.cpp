#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)	for(int i=0;i<n;i++)

int main(){
  int	a,b;	cin >> a >> b;
  vector<int>	x(3);
  rep(i,3)	x[i]=i+1;
  
  x[a-1]=0;
  x[b-1]=0;
  for(int i:x)	if(i>0)	cout <<i;
}