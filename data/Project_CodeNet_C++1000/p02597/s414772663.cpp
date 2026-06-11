#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) v.begin(),v.end()

int main() {
  int n;
  cin >> n;
  vector<char> c(n);
  for(int i=0;i<n;i++){
  	cin >> c[i];
  }
  ll count=0;
  for(int i=0;i<n;i++){
  	if(c[i]=='R'){count++;}
  }
  ll co=0;
  for(int i=0;i<count;i++){
  	if(c[i]=='R'){co++;}
  }
  cout << count - co << endl;
}

