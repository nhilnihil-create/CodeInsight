
#include<iostream>
using namespace std;
int main ()
{
int x;
cin>>x;
if (x%1000!=0)
{cout <<(1000-x%1000);}
if (x%1000==0) { cout << (0) ;}
return 0;
}
