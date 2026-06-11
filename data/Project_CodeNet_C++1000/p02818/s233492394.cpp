//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define fixed cout.setf(ios::fixed);
#define Precise cout.precision(7);
using namespace std;
int main()
{
    ll a,b,aa,k,z=0;
    cin>>a>>b>>k;
    aa=a;
    a=max(z,a-k);
    k-=aa;
    if(k>0){
        b=max(z,b-k);
    }


    cout<<a<<" "<<b<<endl;
    return 0;
}



