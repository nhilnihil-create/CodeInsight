#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long a,b,c;
    cin>>a>>b>>c;
    long long d;
    d=c-a-b;
    if(d>0 && d*d>4*a*b)
        cout<<"Yes";
    else
        cout<<"No";
}
