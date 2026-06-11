#include<bits/stdc++.h>
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

#define N 10000000
#define nl "\n"
#define pb push_back
#define MOD 1000000007
#define pi acos(-1)
#define f first
#define s second

typedef long long ll;
typedef double dd;
//typedef vector<int> vi;
//typedef vector<ll> vll;

using namespace std;

bool seven(int x)
{
    int mod;
    while(x!=0)
    {
        mod = x%10;
        if(mod == 7)
        {
            return true;
            break;
        }
        x = x/ 10;
    }
    return false;
}

int main()
{
    io;
    //freopen("in.txt" , "r" , stdin);
    //freopen("out.txt" , "w" , stdout);

    ///Let the showdown begin

    int t;
    cin >> t;

    if(seven(t))
        cout << "Yes" << nl;
    else
        cout << "No" << nl;

    /// Atlast DONE 
    return 0;
}
