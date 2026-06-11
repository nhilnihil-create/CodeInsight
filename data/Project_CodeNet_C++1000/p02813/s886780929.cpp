#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
using namespace std;

#define INF 1e9
#define PI 3.141592653589793238
#define N 1000000010
#define mod 1000000007
#define REP(inc, bgn, end) for(int inc=bgn; inc<end; inc++)
typedef long long ll;

int main() {
    int n;cin>>n;
    vector<int> p(n), q(n), ary(n);
    REP(i,0,n) cin>>p[i];
    REP(i,0,n) cin>>q[i];

    REP(i,0,n) ary[i] = i+1;

    map<vector<int>, int>mp;
    do{
        mp[ary] = mp.size();
    }while(next_permutation(ary.begin(), ary.end()));

    int ans = abs(mp[p]-mp[q]);
    cout<<ans<<endl;

    return 0;
}