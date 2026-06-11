#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define ll long long

#define for(i,a,b) for (i=a; i<b; i++)
#define forb(i,a,b) for (i=a; i>b; i--)
#define all(S) S.begin(),S.end()
#define sort(S) sort(all(S))

const int inf = 1e9;
const ll INF = 1e18;

int dp[2019];

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    string s;
    ll i,j,n,m=0;
    cin >> s;
    n=s.size();
    for (i,0,2019)
        dp[i]=0;
    dp[s[0]-'0']++;
    dp[0]++;
    for(i,1,n)
    {
        int q = s[i]-'0';
        bool b = false;
        vector <int> V(2019);
        for (j,0,2019)
        {
            V[(j*10+q)%2019]=dp[j];
            if ((j*10+q)%2019==0)
            {
                b=true;
                m+=dp[j];
                V[(j*10+q)%2019]++;
            }
        }
        if (!b)
            dp[0]++;
        for (j,0,2019)
            dp[j]=V[j];
    }
    cout << m << endl;
    return 0;
}
