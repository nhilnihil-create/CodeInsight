#include <iostream>

using namespace std;

int main()
{
  int H=0;
  int W=0;
  int i;
  int j;
  
  while(1)
  {
    cin >> H >> W;
    
    if(H==0 && W==0)
      goto EXIT;
    
   /* for(i=0;i<H;i++)
    {
      switch(a)
      {
      case 0:check=0; a=1; break;
      case 1:check=1; a=0; break;
      }
      for(j=0;j<W;j++)
      {
        switch(check)
        {
        case 0:cout << "#"; check=1; break;
        case 1:cout << "."; check=0; break;
        }
      }
      cout <<"\n";
    }
  
  cout << "\n";*/
  
  for(i=0;i<H;i++)
  {
    for(j=0;j<W;j++)
    {
      if(i%2==0 && j%2==0)
        cout << "#";
      if(i%2==0 && j%2==1)
        cout << ".";
      if(i%2==1 && j%2==0)
        cout << ".";
      if(i%2==1 && j%2==1)
        cout << "#";
    }
    cout <<"\n";
  }
   cout << "\n";
   
  }
  EXIT:;
}