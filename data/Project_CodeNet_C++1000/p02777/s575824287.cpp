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
    string s,t;
    cin>>s>>t;
    map<string,ll>m;
    cin>>m[s];
    cin>>m[t];
    string u;
    cin>>u;
    m[u]--;
    cout<<m[s]<<" "<<m[t]<<endl;
    }
