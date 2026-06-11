#include<iostream>
using namespace std;

const int N = 1e5+2;
bool check(int z)
{ int i;
   for(i=2;i*i<=z;i++)
    { if(z%i==0)
       return false;
    }
    return true;
}
int main()
{
 int x;
    cin>>x;
    while(!check(x))x++;
    cout<<x;
 }      