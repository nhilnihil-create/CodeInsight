#include <bits/stdc++.h>
#define rep(i,n) for(long long i=0; i<n; i++)
#define Rep(i,n) for(long long i=1; i<n; i++)
#define ll long long
#include <math.h>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <vector>


using namespace std;
#define PI acos(-1)

int main(){
    ll N,K;
    cin>>N>>K;
    N-=(N/K)*K;
     ll ans=N;
    vector<int>v;
    bool ok=true;
    while(ok){
        
        if(ans<=llabs(N-K))ok=false;
        ans=min(ans,llabs(N-K));
        N=llabs(N-K);
    }
    cout<<ans<<endl;
}

