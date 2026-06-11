#include<iostream>
using namespace std;
int main()
{
  int n,m,t,i;
  cin >> n >> m;
  if(n%2==1){
    for(i=1;i<=m;i++)
      cout << i << " " << n-i << endl;
  }else{
    t=n/2;
    for(i=1;i<=t/2&&m>0;i++,m--)
      cout << i << " " << t+1-i << endl;
    for(i=1;i<=(t-1)/2&&m>0;i++,m--)
      cout << t+i << " " << n-i << endl;
  }
  return 0;
}