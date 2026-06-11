#include <bits/stdc++.h>
using namespace std;


//defines...
#define ll long long
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define mp make_pair
#define in insert
#define pi 2*acos(0.0)1
#define srt(s) sort(s.begin(),s.end())
#define all(x) x.begin(),x.end()

const ll mod=1e9+7;
const ll MX=2e5+5;

//code goes from here...



int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);
#endif

    boost
    //---------------------------------
    int n;
    cin >> n;
    vector <int > v(n);
    for(auto &i : v) cin >> i;
    srt(v);
    ll s=v[0],l=v[n-1],ss=INT_MAX;
    for(int i=s;i<=l;i++)
    {
        ll cur=0;
        for(int j=0;j<n;j++)
        {
            cur+=((v[j]-i)*(v[j]-i));
        }
        ss=min(ss,cur);
    }
    cout << ss<< endl;
    
    //---------------------------------
    
    return 0;
}
