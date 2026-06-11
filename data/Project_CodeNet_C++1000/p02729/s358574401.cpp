// I'm a f*cking looser
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fasino ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
#define input(A) for(auto &i:A) cin>>i;
int ncr(int n, int k) 
{ 
    int res = 1; 
    if(k>n) return 0;
    if (k > n - k) 
        k = n - k; 
    for (int i = 0; i < k; ++i) { 
        res *= (n - i); 
        res /= (i + 1); 
    } 
    return res; 
} 
signed main()
{
    fasino
    int n,m;
    cin>>n>>m;
    cout<<ncr(n,2) + ncr(m,2);
    return 0;
}