#include <iostream>
using namespace std;

int main()
{
  int a,b,c,t,ans;
  cin >> a >> b >> c;
  if(a>b){
    t=a;
    a=b;
    b=t;
  }

  for(int i=a;i<=b;i++){

    if(c%i==0) ans++;
  }
		 
    cout << ans++ << endl;
  

  return 0;
}