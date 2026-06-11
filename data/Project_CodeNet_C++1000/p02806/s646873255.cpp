#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define fr(i,n) for(int i=0;i<(n);++i)
#define Fr(i,n) for(int i=1;i<=(n);++i)
#define ifr(i,n) for(int i=(n)-1;i>=0;--i)
#define iFr(i,n) for(int i=(n);i>0;--i)
 

int main(void) {
  int n;cin>>n;
  vector<pair<string, int>> st(n);
  int sum = 0;
  fr(i,n) {
    cin>>st[i].first>>st[i].second;
    sum += st[i].second;
  }
  string x;cin>>x;
  int temp = 0;
  fr(i,n) {
    temp += st[i].second;
    if(x == st[i].first) break;
  }
 
  
 cout << sum - temp << endl;
  return 0;
}