#include <iostream>
using namespace std;

bool judge(int s){
  if(s==2 || s==3){return true;}
  for(int j=2;j*j<=s;j++){
    if(s%j==0){return false;}
    if((j+1)*(j+1)>s){return true;}
  }
}

int main()
{
  while(1){
  int n;
  int cnt=0;

  cin >> n;

  if(n==0){break;}
      
  for(int i = n+1;i <= 2*n;i++)
    {
      if( judge(i) )
	{
	 
		  cnt++;
 
	}
    }
  cout << cnt << endl;
  }
}

