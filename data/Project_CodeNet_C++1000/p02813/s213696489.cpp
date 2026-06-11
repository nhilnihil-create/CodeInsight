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
using P =pair<int,int>;

int main(){
    int n;
    cin>>n;
    vector<int> p(n),q(n);
    rep(i,n) cin>>p[i];
    rep(i,n) cin>>q[i];
    vector<int> a(n);
    rep(i,n)a[i]=i+1;
    
    map<vector<int>,int> mp;
    do{
        mp[a] =mp.size();
    } while (next_permutation(a.begin(),a.end()));
    cout<<abs(mp[p]-mp[q])<<endl;
    }
