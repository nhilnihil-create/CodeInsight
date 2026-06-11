#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
long long  n,k,n1;
cin>>n>>k;
long long  mn,d;
d=n%k;
mn=abs(k-d);

cout<<min(mn,d)<<endl;
}
