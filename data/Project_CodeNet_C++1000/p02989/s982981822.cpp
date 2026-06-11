#include <bits/stdc++.h>
#define INF (1e18+1)
#define LL long long
#define rep(i, c) for(int i=0;i<(int)(c);i++)
//ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main()
{

    int n = 0;
    cin >> n;
    
    std::vector<long long> v(n);
    rep(i,n) cin >> v[i];
    
    // ABCs ANS - v[i]
    //                      > #ABCs == #ARCs
    // ARCs v[i] - ANS
    
    sort(v.begin(),v.end());
    
    int answer = v[v.size()/2]-v[v.size()/2-1];
    
    cout<<answer<<endl;

}