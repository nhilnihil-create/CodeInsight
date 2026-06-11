#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
int p,q,r;
cin>>p>>q>>r;
int a[3]={p+q,q+r,p+r};

int index=min_element(a,a+3)-a;

cout<<a[index]<<endl;



return 0;
}