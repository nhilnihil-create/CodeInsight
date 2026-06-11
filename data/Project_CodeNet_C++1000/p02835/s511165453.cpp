#include <bits/stdc++.h>
using namespace std;

void fun(int A1, int A2, int A3)
{
      if((A1+A2+A3)>=22)
      {
           cout<<"bust";
      }
      else
       cout<<"win";
}
int main()
{
     int A1,A2,A3;
     cin>>A1>>A2>>A3;
    fun(A1,A2,A3);
}