#include<bits/stdc++.h>
#define Vsort(a) sort(a.begin(), a.end())
#define rep(i,n) for(int i = 0; i < (n); i++)
#define Srep(i,a,n) for(int i = (a); i < (n); i++)
using namespace std;

int main(){
  int n;
  bool ans=false;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  Vsort(a);
  rep(i,n-1) if(a[i] == a[i+1]) ans=true;
  ans ? cout << "NO" : cout << "YES";
}
