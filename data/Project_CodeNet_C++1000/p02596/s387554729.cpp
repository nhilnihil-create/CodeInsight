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
    map<int, int>m;
    int rem = 7%k, freq = 1;  
    while(true)
    {
        if(rem==0)
        {
            cout<<freq<<endl;
            break;
        }
        if(m.find(rem)!=m.end())
        {
            cout<<-1<<endl;
            break;
        }
        m[rem]=1;
        freq++;
        rem = (10*rem + 7)%k;
    }    
}