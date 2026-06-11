#include <bits/stdc++.h>
using namespace std;
long long  a,b,c,k,s,sum;

int main(){
 cin>>k;
 for(a=1;a<=k;a++){
    for(b=1;b<=k;b++){
        for(c=1;c<=k;c++){
            s+=__gcd(c,__gcd(a,b));

        }
    }
 }
 cout<<s;
    return 0;}


