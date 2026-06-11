#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2") 
#pragma GCC optimization ("unroll-loops")

using namespace std;
using ll = long long;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F first
#define S second
#define Ceil(x, y) ((x+y-1)/y)
#define PI acos(-1)
const int mod = (int) 1000000007;
const int N = 3e5 + 10;
vector<int> h(N), w(N), cntH(N), cntW(N);
map<int, bool> M[N];
void solve()
{
    int H, W, m;
    cin>>H>>W>>m;
    for(int i=0; i<m; i++)
    {
        cin>>h[i]>>w[i];
        cntH[h[i]]++, cntW[w[i]]++;
        M[h[i]][w[i]] = true;
    }
    int maxh = 0, maxw = 0;
    for(int i=0; i<N; i++)
    {
        maxh = max(maxh, cntH[i]);
        maxw = max(maxw, cntW[i]);
    }
    vector<int> mxH, mxW;
    for(int i=0; i<N; i++)
    {
        if(cntH[i] == maxh)
            mxH.push_back(i);
        if(cntW[i] == maxw)
            mxW.push_back(i);
    }
    int ans = 0;
    for(int i=0; i<mxH.size(); i++)
    {
        for(int j=0; j<mxW.size(); j++)
        {
            ans = max(ans, maxh+maxw - M[mxH[i]][mxW[j]]);
            if(ans == maxh+maxw)
                break;
        }
        if(ans == maxh+maxw)
            break;
    }
    cout<<ans;
}
 

int main(int argc, char *argv[])
{
    clock_t clk_start = clock();
    fast;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
 
    int cases = 1;
    // cin>>cases;
    for(int i=1; i<=cases; i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    cerr<<"Execution Time: "<<fixed<<double(clock() - clk_start)/double(CLOCKS_PER_SEC)<<setprecision(6)<<" sec\n"; 
}
