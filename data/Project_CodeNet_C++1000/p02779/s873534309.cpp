#include<bits/stdc++.h>
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

#define N 4e7
#define nl "\n"
#define f first
#define s second
#define pi acos(-1.0)
#define MOD 1000000007
#define pb push_back
#define vector<int> VI;
#define vector<long long> VII;

typedef long long ll;
typedef double db;

using namespace std;
set<int>st;
int main()
{
    io;
    //freopen("in.txt" , "r" , stdin);
    //freopen("out.txt" , "w" , stdout);

    ///Let the showdown begin

    int t;
    cin >> t;

    int sz=t;
    while(t--)
    {
        int x;
        cin >> x;
        st.insert(x);
    }
    if(sz == (int)st.size())
        cout << "YES" << nl;
    else
        cout << "NO" << nl;

    ///Happily DONE
    return 0;
}
