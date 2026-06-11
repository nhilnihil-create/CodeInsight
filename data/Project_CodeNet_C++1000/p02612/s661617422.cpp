///ShzFahad
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    ld k;
    cin >> n;
    k = ceil(n/1000.0)*1000;
    cout << k-n << endl;


}

