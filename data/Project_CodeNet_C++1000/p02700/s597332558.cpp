#include <bits/stdc++.h>
using namespace std;
long long a,b,c,d;

int main(){
    cin>>a>>b>>c>>d;
    while(a>0&&c>0){
        c-=b;
        a-=d;
    }
    if(c<=0)cout<<"Yes";
    else if(a<=0)cout<<"No";

    return 0;}


