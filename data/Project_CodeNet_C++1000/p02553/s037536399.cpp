#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int a, b, c, d;
    cin>>a>>b>>c>>d;
    if(a*c>b*d && a*c>a*d && a*c>b*c)
        cout<<a*c;
    else if(b*c>b*d && b*c>a*d && b*c>a*c)
        cout<<b*c;
    else if(a*d>b*d && a*d>b*c && a*d>a*c)
        cout<<a*d;
    else
        cout<<b*d;
    return 0;
}