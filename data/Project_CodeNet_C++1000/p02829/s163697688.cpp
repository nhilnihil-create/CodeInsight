#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define pb push_back
#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long ll;
#define reps(i,a,b) for(ll i=ll(a);i<ll(b);i++)
#define rep(i,b) for(ll i=0;i<ll(b);i++)
typedef vector<long long> vll;
typedef vector<pair<int,int>> vii;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int main()
{
    csl;
    int a,b;
    cin >> a >> b;
    map<int,int> m;
    m[a]++,m[b]++;
    int flag = -1;
    for(auto i:{1,2,3})
    {
            if(m[i])
                continue;
            else
                flag = i;
    }

    cout << flag << endl;

}
