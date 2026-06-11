
#include <bits/stdc++.h>
#define LL               long long
#define PB               push_back
using namespace std;
int main(){
  int l,R,c=0; cin >>l>>R;
  int d; cin>>d;
  for (int i=l;i<=R;i++){
    if (!(i%d)) c++;
  }
  cout<< c<<endl;
}