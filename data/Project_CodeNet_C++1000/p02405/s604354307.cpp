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
   for (int j = 0; j < W; j++)
   {
    if ((i + j) % 2 == 0)
    {
     cout << "#";
    }
    else
    {
     cout << ".";
    }
   }
   cout << endl;
  }
  cout << endl;
 }
}
