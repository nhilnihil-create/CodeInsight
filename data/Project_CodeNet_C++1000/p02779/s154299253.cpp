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
    ll n;
    cin>>n;
    set<ll>s;
    ll a;
    rep(i,n){
        cin>>a;
        s.insert(a);
    }
    if(s.size()==n){
        cout<<"YES"<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
    }
