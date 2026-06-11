#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
int a,b;
cin>>a>>b;
cout<<a/b<<" "<<a%b<<" ";
double f;
f=(double)a/b;
cout<<fixed<<setprecision(8)<<f<<endl;
return 0;
}