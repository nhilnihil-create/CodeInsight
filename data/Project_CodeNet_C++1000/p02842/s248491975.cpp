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
    double n,x;
    cin >> n ;
    x=floor(n/1.08);
    if(x*1.08>=n && x*1.08 <(n+1)) cout << x << endl;
    else if((x+1)*1.08>=n && (x+1)*1.08<(n+1)) cout << x+1 << endl;
    else cout << ":(\n";
    
    //---------------------------------
    
    return 0;
}
