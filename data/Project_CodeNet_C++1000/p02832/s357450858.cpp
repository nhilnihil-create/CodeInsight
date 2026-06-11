#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  int n;
  cin >> n;

  vector<int> a(n);
  for(int i=0; i<n; ++i) cin >> a[i];

  int cnt = 1;
  for(int i=0; i<n; ++i){
    if(a[i]==cnt) cnt++;
  }
  if(cnt==1){
    cout << "-1";
    return 0;
  }
  else cout << n-(cnt-1);
}