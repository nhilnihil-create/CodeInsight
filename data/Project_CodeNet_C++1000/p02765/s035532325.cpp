#include<bits/stdc++.h>
using namespace std;

int main(){

int n,r,in;
 cin>>n;
 cin>>r;

 if (n>=10)
    in=r;
 else
    in = r+ (100*(10-n));
 cout<<in;
 return 0;

}