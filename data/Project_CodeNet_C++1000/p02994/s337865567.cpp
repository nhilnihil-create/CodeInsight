#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,l;
  cin >> n >> l;
  int su=0,mi=101;
  for(int i=0;i<n;i++){
    su+=l+i;
    if(abs(mi)>abs(l+i))
      mi=l+i;
  }
  cout << su-mi << endl;
  return 0;
}