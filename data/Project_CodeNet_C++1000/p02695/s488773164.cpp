//#include<bits/stdc++.h> using namespace std;
#include<iostream>
using namespace std;
#include<algorithm>
#include<map>
#include<vector>
#include<set>
#include<stack>
#include<queue> //priority_queue inside queue
#include<deque>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define nl '\n'
typedef long long ll;
typedef unsigned long long ull;
#define f(i,start,end) for(i=start;i<=end;i++)
#define min_heap priority_queue<int, vector<int>, greater<int> >
#define max_heap priority_queue<int>
#define eb emplace_back

bool isPrime(int n)
{
    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0) return false;
    }
    return true;
} //returns true if prime!


int main()
{
    fast;
//int t=0,tc=0; cin >> tc; f(t,1,tc) //testcases
    {
        int n,m,q;
        cin >> n >> m >> q;
        int i,j;
        int a[60],b[60],c[60],d[60];
        
        f(i, 0, q-1)
        {
            cin >> a[i] >> b[i] >> c[i] >> d[i];
            a[i]--;
            b[i]--;
        }
        
        vector<int> x(n+m-1, 1);
        f(i,0, m-2) x[i]=0;
        
        int ans = 0;
        
        do
        {
            int cnt = 1;
            vector<int> y;
            f(i, 0, x.size()-1)
            {
                if(x[i]==1) y.eb(cnt);
                else cnt++;
            }
            //for(auto it: y) cout << it; cout << nl;
            int sums = 0;
            f(i, 0, q-1)
            {
                if(y[b[i]]-y[a[i]]==c[i]) sums += d[i];
            }
            ans = max(ans, sums);
        }
        while(next_permutation(x.begin(), x.end()));
        cout << ans << nl;
    }
    return 0;
}
    