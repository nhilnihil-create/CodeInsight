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
    int k;
    cin>>k;
    int rem = 7%k, freq = 1;
    if(k%2==0 || k%5==0)
        cout<<-1<<endl;  
    else
    {   
        while(rem)
        {
            freq++;
            rem = (10*rem + 7)%k;
        }
        cout<<freq<<endl;
    }    
}