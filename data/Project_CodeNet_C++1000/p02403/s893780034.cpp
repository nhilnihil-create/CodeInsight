#include <iostream>

using namespace std;

int main()
{
  int H;
  int W;
  int i;
  int j;
  
  while(1)
  {
    cin >> H >> W;
    
    if(H==0 && W==0)
      goto EXIT;
    
    for(i=0;i<H;i++)
    {
      for(j=0;j<W;j++)
      {
        cout << "#";
      }
      cout <<"\n";
    }
  
  cout << "\n";
  }
  EXIT:;
}