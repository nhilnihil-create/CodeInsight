#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;
#define int long long int
//#define ll long long int
#define pb push_back
#define vec vector<int>
#define fo(i, n) for (int i = 0; i < n; i++)
#define foo(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define deb(x) cout << #x << " --> " << x << endl;
#define deb1a(v) cout << #v << "--->" << endl; for (auto it : v)  cout << it << " "; cout << endl;
#define deb2a(v) cout << #v << "--->" << endl;for (auto it:v){for(auto it1 : it){cout << it1 << " ";}cout<< endl;}
#define deb3a(v) cout << #v << "-->" << endl; for(auto it:v){cout << it.fi << " " << it.se << endl;}
#define mod 998244353
#define so(v) sort(v.begin(),v.end())
#define fi first
#define se second
#define db1(x) cout<<#x<<"="<<x<<endl
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<endl
int power(int x, unsigned int y, int p){ int res = 1;x = x % p;while (y > 0)  { if (y & 1)res = (res*x) % p;y = y>>1;  x = (x*x)% p;} return res;}
int mI(int a, int m)  {return power(a, m - 2, m);}
// vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1},{1,1},{1,-1},{-1,1},{-1,-1}};
#define double long double

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    n++;
    vec pos(n+5,1);
    //map<int, int> m;
    vec m(n + 5, 0);
    vec v(n);
    fo(i,n){
        cin >> v[i];
    }
    if(n==1){
        if(v[0]==1){
            cout << 1;
            return 0;
        }
        else{
        cout<<-1;
        return 0;}
    }
    if(v[0]!=0){
        cout << -1;
        return 0;
    }
    int in = 0;
    int ans = 0;
    int curr = 0;
    foo(i,1,n){
        int vall = v[i];
        if(i==n-1)
            vall--;
        while(vall>0){
            if(in>=i){
                cout << -1;
                return 0;
            }
            int fii = pos[in]+curr;
            //db3(i, vall, fii);
            if(fii>vall){
                ans += (vall) * (i - in);
                m[i] -= vall;
                m[in + 1] += vall;
                pos[in] -= vall;
                vall = 0;
            }
            else{
                ans += (fii) * (i - in);
                m[i] -= fii;
                m[in + 1] += fii;
                vall -= fii;
                in++ ;
                curr += m[in];
            }
        }
        //deb(in);
        // deb(pos[in] + m[in]);
    }
    cout << n + ans;
    

}
