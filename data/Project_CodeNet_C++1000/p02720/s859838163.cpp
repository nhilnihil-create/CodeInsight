#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define mp make_pair
#define pb(x) push_back(x)
#define vll vector<long long>
#define pll pair<long long, long long>
#define mll map<long long, long long>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define gcd __gcd
#define clr(x) memset(x, 0, sizeof(x))
#define mod 1000000007LL
#define mod2 998244353LL
#define INF 1e18

typedef long long ll;
typedef long double ld;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> o_tree;

void solve()
{
    ll k;
    cin>>k;
    queue<string> q;
    ll i;
    if(k<=9)
    {
        cout<<k<<"\n";
        return;
    }
    for(i=1;i<=9;i++)
    {
        q.push(string(1,char('0'+i)));
    }
    ll si = 9;
    while(si<k)
    {
       string pre = q.front();
       q.pop();
    //    cout<<pre<<"\n";
       ll cc = (int)(pre.back()-'0');
       if(cc==0)
       {
            string temp = pre;
            temp+='0';
            q.push(temp);
            si++;
            if(si==k)break;
            temp=pre;
            temp+='1';
            q.push(temp);
            si++;
       }
       else if(cc==9)
       {
            string temp = pre;
            temp+='8';
            q.push(temp);
            si++;
            if(si==k)break;
            temp=pre;
            temp+='9';
            q.push(temp);
            si++;
       }
       else{
            string temp = pre;
            temp+=char(cc-1+'0');
            q.push(temp);
            si++;
            if(si==k)break;
            temp=pre;
            temp+=char(cc+'0');
            q.push(temp);
            si++;
            if(si==k)break;
            temp=pre;
            temp+=char(cc+1+'0');
            q.push(temp);
            si++;
            // if(si==k)break;
       }
    }
    cout<<q.back()<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (fopen("input.txt", "r"))
    {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    cout << setprecision(20);

    ll t = 1;

    // cin>>t;

    while (t--)
    {
        solve();
    }

    return 0;
}