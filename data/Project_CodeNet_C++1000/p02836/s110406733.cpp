#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 string a;
 cin>>a;
 int n= a.length(),f=0;
 if(n==1)
    cout<<"0";
 else{
 if(n%2==1)
 {
     f=1;
 }
 int i=0,j=n-1,c=0;
 while(1){
    if(a[i]!=a[j])
    {
        c++;
    }
    i++,j--;
    if(i==j && f==1)
        break;
    if((i-1)==(j) && f==0)
      break;

 }
cout<<c;
}}
