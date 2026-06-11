#include<iostream>
using namespace std;
int main()
{

int h,a,s=0,k;
cin>>h>>a;
for(int i=0;i<a;i++)
{  cin>>k;
    s=s+k;
}
if(s>=h)
{
    cout<<"Yes"<<endl;
}
else
{
    cout<<"No"<<endl;
}
    return 0;


}
