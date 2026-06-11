#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include <string>
const int mxN=1e5;
const int maxN=5e3;
#define ld long double
#define pb push_back
#define mp make_pair
#define ins insert
#define vi vector<int>

int main()
{
    ll n;
    cin >> n;
    string s="";
    while(n>0)
    {
        ll ost=n%26;
        n/=26;
        if(ost==0)
        {
            n--;
            s='z'+s;
        }
        else
            s=(char('a'+ost-1))+s;
    }
    cout << s;
}