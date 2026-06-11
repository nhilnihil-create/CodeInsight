#include<bits/stdc++.h>
using namespace std;
long long gcd(long long x,long long y){
    while(x && y){
        x%=y;
        if(x==0)break;
        y%=x;
    }
    return x+y;
}
int main(){
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    a--;
    long long lcm=c*d/gcd(c,d);
    cout<<b-b/c-b/d+b/lcm-a+a/c+a/d-a/lcm<<endl;
    return 0;
}
