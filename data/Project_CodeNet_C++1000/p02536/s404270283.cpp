#include<bits/stdc++.h>
#include<atcoder/dsu>
#define ll long long int
using namespace atcoder;
using namespace std;
 
int main(){
  int n, m;
  cin >> n >> m;
  
  dsu d(n);
  for (int i=0; i<m; i++){
  	int a, b;
    cin >> a >> b;
    a--; b--;
    d.merge(a, b);
  }
  
  cout << (int)d.groups().size() - 1 << endl;
}