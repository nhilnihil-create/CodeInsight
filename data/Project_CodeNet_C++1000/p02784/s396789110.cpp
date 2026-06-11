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
    ll h,n;
    cin>>h>>n;
    ll a;
    ll sum=0;
    rep(i,n){
        cin>>a;
        sum+=a;
    }
    if(h<=sum){
        cout<<"Yes"<<endl;
        return 0;
    }
    cout<<"No"<<endl;
    }
