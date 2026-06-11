#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long
#define float long double
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define endl '\n'
#define pii pair<int, int>
#define min3(a,b,c) min(a, min(b, c))
#define max3(a,b,c) max(a, max(b, c))
#define all(x) x.begin(), x.end()
#define fill(a,b) memset(a, b, sizeof(a))
#define sz(x) (int)x.size()
#define sp(x) setprecision(x)
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define bs binary_search

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin>>n;
    int a=0,b=0,c=0,d=0;
    for(int i=0;i<n;i++){
        string s; cin>>s;
        if(s=="AC") a++;
        else if(s=="WA") b++;
        else if(s=="TLE") c++;
        else d++;
    }
    cout<<"AC x "<<a<<endl;
    cout<<"WA x "<<b<<endl;
    cout<<"TLE x "<<c<<endl;
    cout<<"RE x "<<d<<endl;
  
}