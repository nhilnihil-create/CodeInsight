#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define ll long long
int main() {
   ll x,k,d;
   cin>>x>>k>>d;
   x=abs(x);
   ll str= min(k,x/d);
   k-= str;
   x-= str*d ;
   if(k%2==0)
    cout<<x<<endl;
else cout<< abs(d-x)<<endl; 
    
}
