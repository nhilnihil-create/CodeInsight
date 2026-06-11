#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double w,h,x,y;
    cin>>w>>h>>x>>y;
    double ans=(w*h)/2.0;
    cout<<fixed<<setprecision(10)<<ans<<" ";
    if(x==w/2&&y==h/2)
        cout<<"1"<<endl;
    else
        cout<<"0"<<endl;
    return 0;
}