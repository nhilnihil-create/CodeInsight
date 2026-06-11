#include<bits/stdc++.h>
using namespace std;
int main()
{
int A,B,a,b,num;
cin>>A>>B;
num=(A+B)/2;
a=A-num;
b=B-num;
if(abs(a)==abs(b))
cout<<num<<endl;
else
cout<<"IMPOSSIBLE"<<endl;
return 0;
}
