//Ahadul Haque, MBSTU,ICT
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mk make_pair
#define TEST int test; cin >> test ;while(test--)
#define endl "\n"
int main()
{
    ll n;
    cin>>n;
    ll cnt=0,cnt1=0;
    for(int i=0;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
        if(x==y)
        {
            cnt++;
            if(cnt==3)
                cnt1=1;
        }
        else
            cnt=0;
    }
    if(cnt1==1)
        cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;


    return 0;
}





