#include<bits/stdc++.h>
using namespace std;
int main(){
    
    long long a,b,c,d=0,i;
    cin>>a>>b;
    if(a==1)
    c=300000;
    else if(a==2)
    c=200000;
    else if(a==3)
    c=100000;
    else
    c=0;
    if(b==1)
    c=c+300000;
    else if(b==2)
    c=c+200000;
    else if(b==3)
    c=c+100000;
    else
    c=c+0;
    if(a==1&&b==1)
    c=c+400000;
    cout<<c;
    return 0;
}
