#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const ll p=1000000007;
int main(){
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;
  int cnt=0;
  rep(i,n-1){
    if(s[i]==s[i+1])cnt++;
  }
  cout << min(n-1,cnt+2*k) << endl;
}
