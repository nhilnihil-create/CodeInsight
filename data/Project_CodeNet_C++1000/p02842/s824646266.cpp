#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  int N;

  cin >> N;

  int div=(double)N/1.08;
  int ans;
  bool flag=false;
  
  for (int i = 0; i < 2; i++)
  {
    if(N==(int)((double)(div+i)*1.08)){
      flag=true;
      ans=div+i;
      // cout << (double)(div+i)*1.08 << endl;
      // cout << div << endl;
    }
  }
  if(flag){
    cout << ans << endl;
  }else{
    cout << ":(" << endl;
  }
  return 0;
}