#include <iostream>

using namespace std;

int IsPrime (int n);

int main(void){

  int n;
  int max;
  int count;

  while(cin >> n&&n){

    count=0; 
    max=2*n;

    for(int i=n+1;i<=max;i++){
      if(IsPrime(i))
	count++;
    }

      cout << count <<endl;
    
  }


  
  return 0;

}

int IsPrime (int n)
{
  int i;

  if (n < 2)
    return 0;
  else if (n == 2)
    return 1;

  if (n % 2 == 0)
    return 0;

  for (i = 3; i <= n / i; i += 2)
    if (n % i == 0)
      return 0;
  return 1;
}