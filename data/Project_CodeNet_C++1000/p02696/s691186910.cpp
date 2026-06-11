#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int a,b,n;
    cin>>a>>b>>n;
    int x=a; 
    if(n >= b){
        long long int m=(a*(b-1))/b - (a*((b-1)/b));
         cout<<m<<endl;
    }
    else{
          long long int m=(a*(n))/b - (a*((n)/b));
         cout<<m<<endl;  
    }
return 0;
}