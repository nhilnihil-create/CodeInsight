#include <bits/stdc++.h>
using namespace std;

#define	rep(i,n)	for(int i=0;i<n;i++)

int main() {
  int n;	cin >> n;
  vector<int>	p(n);
  vector<int>	q(n);
  rep(i,n)	cin >> p[i];
  rep(i,n)	cin >> q[i];
  
  vector<int>	data(n);
  rep(i,n)	data[i]=i+1;
  
  int a=0;
  int b=0;
  int c=1;
  do{
    bool ok=true;
    rep(i,n){
      if(data[i]!=p[i]){
        ok=false;
        break;
      }
    }
    if(ok)	a=c;
    ok=true;
    rep(i,n){
      if(data[i]!=q[i]){
        ok=false;
        break;
      }
    }
    if(ok)	b=c;
    c++;
  }while(next_permutation(data.begin(),data.end()));
  
  cout << abs(a-b);
  
}
