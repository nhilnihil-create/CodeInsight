#include <bits/stdc++.h>
#define ll long long
#define ch char
#define st string
using namespace std;
ll a,b,c,d,e,f,g,h;
st s;
vector<ll>vc;
void Urvatullo_Atoev()
{
    cin>>a;
    while(a/=2)
    {
       b++;
       b*=2;
    }
    cout<<b+1;
}
int main()
{
    Urvatullo_Atoev();
}
