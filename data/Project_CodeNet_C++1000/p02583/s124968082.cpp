#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  int n; cin >>n;
  vector<int> l(n);
  for(int i=0; i<n; ++i) cin >> l[i];

  int cnt = 0;

  for(int i=0;  i<n; ++i){
    for(int j=0; j<i; ++j){
      for(int k=0; k<j; ++k){
        int a = l[i];
        int b = l[j];
        int c = l[k];
        if(a != b && b != c && a != c){
          if(a+b>c && a+c>b && b+c>a) cnt++;
        }
      }
    }
  }

  cout << cnt << endl;
}