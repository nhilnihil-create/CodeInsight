#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
int main() 
{
 
int a,b,c;
cin>>a>>b>>c;
int a1=a+b+c;
int a2=a+b+c-max({a,b,c});
cout<<a2;
return 0;
}