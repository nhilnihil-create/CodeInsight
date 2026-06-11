#include<iostream>
using namespace std;
int main()
{
long long int a, s;
int b, c;
cin>>a;
scanf("%d.%d", &b, &c);
b=b*100+c;
s=b*a/100;
cout<<s<<endl;
return 0;
}