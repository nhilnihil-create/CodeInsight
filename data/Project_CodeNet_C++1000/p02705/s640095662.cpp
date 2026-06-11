#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll lcm(ll a,ll b){return a*b/__gcd(a,b);}
int main()
{
    cout.precision(10);
    int n;
    cin>>n;
    cout<<fixed<<2*acos(-1.0)*n<<endl;
}
