/*;

THE BEST IS YET TO COME
*/
#include <bits/stdc++.h>
using namespace std;
#define r(i, s, l) for (int i = s; i < l; i++)
#define rr(i,s,l) for(int i=s;i>=l;i--)
#define mod 1000000007
#define int long long
#define INT_BITS 32
#define ld long double
#define pp pair<int,int>
#define ss second
#define ff first
#define INF 1e18
#define N 2000005
#define all(a) a.begin(), a.end()
#define pb push_back
#define endl "\n"
using namespace std;
void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

signed main()
{


    string s;
    cin>>s;
    r(i,0,s.length()-1)
    if(s[i]==s[i+1])
    {
       cout<<"Bad";
       return 0;
    }

    cout<<"Good";


	return 0;
}

