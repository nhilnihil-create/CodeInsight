#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll A,B,N;
    cin >> A >> B >> N;
    ll x = min(N,B-1);
    cout<<(ll)(floor(A*x/B)-A*floor(x/B))<<endl;
}