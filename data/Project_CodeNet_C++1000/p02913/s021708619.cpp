#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
 
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define mod 1000000007
#define inf 1e18+42
#define endl "\n"

#define out1(a) cout<<#a<<" "<<a<<endl
#define out2(a,b) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<endl
#define out3(a,b,c) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<endl

#define rep(i,a,b) for(int i=a;i<b;i++)
#define repr(i,a,b) for(int i=a;i>=b;i--)
#define fori(it,A) for(auto it=A.begin();it!=A.end();it++)

#define ft first
#define sd second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define zero(x) memset(x,0,sizeof(x));
 
using namespace std;

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
//Z function is the greatest number of character starting from position i that coincide with first character of s
//eg. "aaaaa" = [0,4,3,2,1] the first element of the array is immaterial
vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);

    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
        {
            z[i] = min (r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
        {
            ++z[i];
        }
        if (i + z[i] - 1 > r)
        {
            l = i, r = i + z[i] - 1;
        }
    }
    return z;
}

//START OF CODE ->->->->->->->

void solve()
{
    int n;
    cin>>n;

    string s;
    cin>>s;

    int len = 0;
    int ans = 0;
    while( len < s.length() )
    {
        string str = s.substr(len,s.length()-len);
        vector<int> z_val = z_function(str);

        rep(i,0,z_val.size())
        {
            if ( i >= z_val[i] )
            {
                ans = max(ans,z_val[i]);
            }
        }
        len++;
    }

    cout<<ans<<endl;

}

//END OF CODE ->->->->->->->->

signed main()
{
    fast;
    int t = 1;
    // cin>>t;

    while(t--)
    {
        solve();
    }
    return 0;
}

