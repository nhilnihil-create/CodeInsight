#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <functional>
#include <string>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <random>
#include <unordered_map>
#include <unordered_set>
#define ll long long
#define fr(i,k,N) for(ll i=k; i<N;i++)
#define rep(i,N) for(ll i=0; i<N;i++)
#define alll(v) v.begin(),v.end()
using namespace std;
template <class X> void pr(X test){cout<<test<<endl;}
template <class X> void prr(X test){for(auto it:test){cout<<it;}cout<<endl;}

int main() {
    ll n;
    cin>>n;
    vector<ll> v(n);
    rep(i, n) cin>>v[i];
    // prr(v);
    ll level = 1;
    rep(i, n) {
        if (i ==0)
        printf("node %ld: key = %ld, left key = %ld, right key = %ld, \n",i+1,v[i],v[(2*i+1)],v[(2*i+2)]);
        else if((2*i+2)<n)
        printf("node %ld: key = %ld, parent key = %ld, left key = %ld, right key = %ld, \n",i+1,v[i],v[(i+1)/2-1],v[(2*i+1)],v[(2*i+2)]);
        // cout << i+1 << " " << v[i] << " " << v[(2*i+1)] <<" "<< v[(2*i+2)] << endl;
        else if((2*i+1)<n)
        printf("node %ld: key = %ld, parent key = %ld, left key = %ld, \n",i+1,v[i],v[(i+1)/2-1],v[(2*i+1)]);
        // cout << i+1 << " " << v[i] << " " << v[(2*i+1)] << endl;
        else 
        printf("node %ld: key = %ld, parent key = %ld, \n",i+1,v[i],v[(i+1)/2-1]);
        // cout << i+1 << " " << v[i] << endl;
    }

}
