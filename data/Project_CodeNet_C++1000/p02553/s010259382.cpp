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
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll z=a*c;
    ll z1=a*d;
    ll z2=b*c;
    ll z3=b*d;
    cout<<max(z,max(z1,max(z2,z3)));

    return 0;
}
