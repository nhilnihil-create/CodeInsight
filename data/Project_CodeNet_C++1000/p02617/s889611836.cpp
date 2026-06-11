#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(int)(n);i++)
int main(){
  long n;
  cin >> n;
  long nod = n*(n+1)*(n+2)/6;
  long edg = 0;
  rep(i,n-1){
    long u,v;
    cin >> u >> v;
    if(u > v) swap(u,v);
    edg += u * (n-v+1);
  }
  cout << nod - edg << endl;
}

