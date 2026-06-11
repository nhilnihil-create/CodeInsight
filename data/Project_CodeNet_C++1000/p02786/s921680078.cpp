#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(void){
  ll h; cin>>h;
  ll res=1; while(h>>=1) ++res;
  cout<<((ll)1<<res)-1;
  return 0;
}
