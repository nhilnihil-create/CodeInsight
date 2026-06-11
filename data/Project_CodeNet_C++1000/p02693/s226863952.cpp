#include<bits/stdc++.h>
#define Vsort(a) sort(a.begin(), a.end())
#define rep(i,n) for(int i = 0; i < (n); i++)
#define Srep(i,a,n) for(int i = (a); i < (n); i++)
#define ll long long
#define P pair<int, int>
using namespace std;

int main(){
  int k,a,b,judge=0;
  cin >> k >> a >> b;
  for(int i = a; i < b + 1; i++){
    if(i % k == 0) judge++;
  }
  if(judge != 0) cout << "OK" << endl;
  else cout << "NG" << endl;
}
