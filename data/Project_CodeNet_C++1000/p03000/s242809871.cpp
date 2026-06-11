#include<bits/stdc++.h>
#define PI 3.141592653589
#define ll long long
using namespace std;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  int n, x;
  cin >> n >> x;
  vector<int> l(n);
  l[1] = 0;
  for(int i=1; i<n+1; ++i) cin >> l[i];

  int d = 0, cnt = 0;
    
  for(int i=0; i<n+1; ++i){
    d += l[i];
    if(d>x) break;
    cnt++;
  }

  cout << cnt;
   return 0;
}