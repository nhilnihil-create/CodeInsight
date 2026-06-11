#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t,j,p,r,i,n;
    cin>>n;
    if(n<=9)
    cout<<n;
    else if(n>=10&&n<100)
    cout<<9<<endl;
    else if(n>=100&&n<1000)
    cout<<n-100+10;
    else if(n>=1000&&n<10000)
    cout<<909;
    else if(n>=10000&&n<100000)
    cout<<n-10000+910;
    else if(n==100000)
    cout<<90909;
    return 0;
}
