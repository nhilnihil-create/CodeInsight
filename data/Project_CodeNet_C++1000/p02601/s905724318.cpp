#include <iostream>
#define rep(i,n) for(int i=0; i<n;i++)
using namespace std;

int main()
{
  int a,b,c,k,i=0;
  cin >> a >> b >> c >> k;
  while(i<k){
    if(a>=b)
      b=b*2;
    else if(c<=b)
      c=c*2;
    if(a<b && b<c) break;
    i++;
  }
  if(i==k) cout << "No\n";
  else cout << "Yes\n"; 
  return 0;
}