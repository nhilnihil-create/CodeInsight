#include <iostream>

#define N 8

using namespace std;

int main(void)
{
  int num[N];
  while(true)
  {
    for(int i = 0; i < N; i++)
    {
      if(!(cin >> num[i])) goto END;
    }
    int hit = 0, blow = 0;
    for(int i = 0; i < 4; i++)
    {
      if(num[i] == num[i+4]) hit++;
      else if(   num[i] == num[4]
	      || num[i] == num[5]
	      || num[i] == num[6]
	      || num[i] == num[7])
	blow++;
    }
    cout << hit << " " << blow << endl;
  }

 END:
  return 0;
}