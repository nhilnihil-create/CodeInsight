#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 5;
ll lcm(ll a,ll b){return a*b/__gcd(a,b);}
int main()
{
    int n,s;
    cin>>n>>s;
    if(s>=n)cout<<"unsafe"<<endl;
    else cout<<"safe"<<endl;
}
