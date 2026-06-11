#include <bits/stdc++.h>
#define rep(i, e, n) for (int i = e; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int inf=1000000007;


int main(){
  ll n;
  cin >> n;
  vector<char> a;
  while(n!=0){
    int val=n%26;
    if(val==0) val+=26;
    a.push_back(val+96);
    n/=26;
    if(val==26) n--;
  }
  int cnt=a.size();
  for(int i=cnt-1; i>=0; i--){
    cout << a[i];
  }
  cout << endl;
  return 0;
}