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
    ll N,M;
    cin>>N>>M;
    ll votesum=0;
    vector<ll>vote(N);
    rep(i,N){
     cin>>vote[i];
     votesum+=vote[i];
    }
    ll sum=0;
    rep(i,N){
        if(votesum/(4.0*M)<=vote[i])sum++;
    }
    if(M<=sum)cout<<"Yes"<<endl;
     else cout<<"No"<<endl;
}

