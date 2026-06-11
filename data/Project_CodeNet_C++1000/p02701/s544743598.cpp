#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 5;
ll lcm(ll a,ll b){return a*b/__gcd(a,b);}
int main()
{
    set<string>s;
    int n;
    cin>>n;
    string o;
    for(int i=0;i<n;i++)cin>>o,s.insert(o);
    cout<<s.size()<<endl;
}
