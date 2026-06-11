//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define fixed cout.setf(ios::fixed);
#define rep1    for( i=0; i<n; i++)
#define Precise cout.precision(7);
using namespace std;

int main()
{
    ll a,b;
    cin>>a>>b;
    if(a==1||b==1)
    cout<<1<<endl;
    else
    cout<<(a*b+1)/2<<endl;

    return 0;
}



