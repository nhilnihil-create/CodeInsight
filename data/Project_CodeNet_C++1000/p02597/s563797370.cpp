#include <bits/stdc++.h>
#include <string>
#include <cmath>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<ll> vll;
 
#define all(v) v.begin(),v.end()
#define test() int t;cin>>t;while(t--) 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int mod = 1e9+7;

int main()
{   
    fastio
    int n;
    string str;
    cin>>n;
    cin>>str;
    int l =str.length();
    int countr = 0, countw = 0, swaps = 0;
    for (int i = 0; i < l; i++)
    {
        if(str[i]=='R')
            countr++;
        else 
            countw++;        
    }
    for (int i = 0; i < countr; i++)
    {
        if(str[i]=='W')swaps++;
    }
    cout<<min(min(countr, countw), swaps);
}