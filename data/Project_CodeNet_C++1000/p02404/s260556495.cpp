#include <iostream>
#include <stdio.h>
 
using namespace std;
 
int main()
{
 int H, W;
 while(scanf("%d %d", &H, &W), H!=0)
 {
  for (int i = 0; i < H; i++)
  {
   if (i == 0 || i == H - 1)
   {
    for (int j = 0; j < W; j++)
    {
     cout << "#";
    }
   }
   else
   {
    for (int j = 0; j < W; j++)
    {
     if (j == 0 || j == W - 1)
     {
      cout << "#";
     }
     else
     {
      cout << ".";
     }
    }
   }
   cout << endl;
  }
  cout << endl;
 }
}
