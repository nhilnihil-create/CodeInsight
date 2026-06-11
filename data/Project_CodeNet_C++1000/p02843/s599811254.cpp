//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define fixed cout.setf(ios::fixed);
#define Precise cout.precision(7);
using namespace std;
int main()
{
    ll n,div,rem,fived;
    cin>>n;
    div=n/100;
    rem=n%100;
    fived=rem/5;
    if(rem%5)
        fived++;
    if(fived<=div)
    cout<<"1"<<endl;
    else
    cout<<"0"<<endl;

    return 0;
}



