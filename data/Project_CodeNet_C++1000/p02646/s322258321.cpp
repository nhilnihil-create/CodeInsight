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
    ll a,v,b,w,t;
    cin>>a>>v>>b>>w>>t;
    ll distance=llabs(a-b);
    ll speed=v-w;
    if(distance<=(speed*t)){
        cout<<"YES"<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
    }
