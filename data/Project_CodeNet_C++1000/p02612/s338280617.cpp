#include<bits/stdc++.h>
using namespace std;

int main()
{ int n;
 cin>>n;
 n=n%1000;
 if(n)
 cout<<abs(1000-n);
 else
 cout<<0;
}