//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define fixed cout.setf(ios::fixed);
#define Precise cout.precision(7);
using namespace std;

int main()
{
    ll n,x,prev,cnt=1;
    cin>>n;

    cin>>x;
    prev=x;
    while(--n)
    {
        cin>>x;
        if(x<prev)
        {
            prev=x;
            cnt++;
        }
    }


    cout<<cnt<<endl;


    return 0;
}



