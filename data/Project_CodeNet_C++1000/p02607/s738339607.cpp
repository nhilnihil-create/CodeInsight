#include <bits/stdc++.h>
using namespace std;


int main(){
 long long n,b,x,m,c=0;
 cin >>n;
 int a[n];
 for(int i=0;i<n;i++)cin >>a[i];

 for(int i=0;i<n;i++){
    if( (i+1)%2!=0 && a[i]%2!=0)c++;

 }
 cout << c << endl;
}
