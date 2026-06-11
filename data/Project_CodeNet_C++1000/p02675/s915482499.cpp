#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n;
    cin>>n;
    ll k=n%10;
    if(k==0 || k==1 ||k==6 || k==8)
    {

        cout<<"pon"<<endl;
    }
    else if(k==3)
    {
        cout<<"bon"<<endl;
    }
    else{
        cout<<"hon"<<endl;
    }



}
