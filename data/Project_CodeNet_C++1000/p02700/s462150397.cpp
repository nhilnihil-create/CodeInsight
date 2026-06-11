#include <bits/stdc++.h>
using namespace std;
int main() {
  int a,b,c,d; cin>>a>>b>>c>>d;
  while(1){
    c-=b; if(c<1) break;
    a-=d; if(a<1) break;
  }
  cout<<(c<1?"Yes":"No");
}