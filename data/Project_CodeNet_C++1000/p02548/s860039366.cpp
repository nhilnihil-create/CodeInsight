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
   ll cnt=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;i*j<n;j++)
        {
            cnt++;
        }
    }
    cout<<cnt<<endl;






    return 0;
}






