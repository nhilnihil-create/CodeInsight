#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
   ll a,b,c=0,d=0,e=0,f=0,g=0,h=0;
   cin>>a>>b>>c;
       d=b+c;
       e=a/d;
       f=a%d;
    g=e*b;
    if(f>=b){g=g+b;}
    else{g=g+f;}
    cout<<g;
}