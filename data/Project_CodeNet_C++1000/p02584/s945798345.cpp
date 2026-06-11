#include<bits/stdc++.h> 
using namespace std;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int main() {
    fast_io;
     long long x,k,d;
     cin>>x>>k>>d;

     long long tmp;

     x=abs(x);

     tmp=min(k,(x/d));

     x-=(tmp*d);
     k-=tmp;

     if(k%2==0) {
         cout<<x<<endl;
     }
     else {
         cout<<abs(x-d)<<endl;
     }


}


