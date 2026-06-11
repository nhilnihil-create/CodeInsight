#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t n,a,b;
  cin >> n >> a >> b;
  if((b-a)%2==0)cout << (b-a)/2 << endl;
  else if((b-a)%2!=0){
    int64_t mind;
    mind=min(a-1,n-b);
    int64_t dis=(b-a-1)/2;
    cout << mind+dis+1 << endl;
  }
}
