//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define fixed cout.setf(ios::fixed);
#define Precise cout.precision(7);
using namespace std;

int main()
{
    ll n,x,i,j;
    cin>>n;
    bool ok=1;
    for( i=0; i<n; i++)
    {
        cin>>x;
        if(x%2==0)
        if(x%3&&x%5){
            ok=0;
        }
    }
    if(ok)
        cout<<"APPROVED"<<endl;
    else
        cout<<"DENIED"<<endl;

    return 0;
}



