/**
*    author:  souzai32
*    created: 13.08.2020 01:17:53
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

long gcd(long a, long b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}

long lcm(long a, long b)
{
   return a * b / gcd(a, b);
}

int main() {

    long a,b;
    cin >> a >> b;
    long num=gcd(a,b);
    int count=1;

    for(long i=2; i*i<=num; i++){
        if(num%i!=0) continue;
        while(num%i==0){
            num/=i;
        }
        count++;
    }
    if(num!=1) count++;

    cout << count << endl;

    return 0;
}