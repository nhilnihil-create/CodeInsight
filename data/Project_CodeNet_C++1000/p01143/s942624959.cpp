#include <iostream>
using namespace std;
int main()
{
  int n,m,p,i,s,a[100];
  for(;;){
    cin >> n >> m >> p;
    if(n==0 && m==0 && p==0) break;
    s = 0;
    for(i=0;i<n;i++){
      cin >> a[i];
      s += a[i];
    }
    if(a[m-1] == 0) cout << "0" << endl;
    else{
      s = s * (100 - p);
      cout << s / a[m-1] << endl;
    }
  }
  return 0;
}