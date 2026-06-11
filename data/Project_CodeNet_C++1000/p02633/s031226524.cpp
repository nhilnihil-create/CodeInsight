#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (long long)((a).size())
const double pi = 3.14159265358979323846;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

    ll d;
    cin>>d;
    cout<<((360)/__gcd(d,360ll));
}