#include<bits/stdc++.h>
const long int p=1e9+7;

using namespace std;

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void fun()
{
   int x,y,z;
   cin>>x>>y>>z;

   swap(x,y);
   swap(x,z);

   cout<<x<<" "<<y<<" "<<z;

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    fun();
    return 0;
}
