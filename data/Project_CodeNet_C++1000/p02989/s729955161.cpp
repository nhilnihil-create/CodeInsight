#include<bits/stdc++.h>
#define PI 3.141592653589
#define ll long long
using namespace std;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int  main(){
  int n;
  cin >> n;
  vector<int> d(n);
  int mx = 0;
  for(int i=0; i<n; ++i)cin >> d[i];
  sort(d.begin(), d.end());

  int ans = d[d.size()/2] - d[d.size()/2-1];

  cout << ans;
  return 0;
}