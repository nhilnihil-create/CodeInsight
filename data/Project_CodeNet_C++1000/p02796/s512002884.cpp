#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<queue>
#include <cmath>
#include<algorithm>
#include<stack>
#include<map>
#include<ctime>
#define rep(i,n) for (int i=0;i<n;i++)
//#include <bits/stdc++.h>
using namespace std;
typedef pair<long int, long int> pl;

bool comp(pl x,pl y){
    if (x.second<y.second) return true;
    else return false;
}

int main(){
    long int N;
    cin>>N;
    vector<long int> X(N), L(N);
    vector<pl> v(N);
    for (int i=0;i<N;i++){
        cin>>X[i]>>L[i];
        v[i].first=X[i]-L[i];
        v[i].second=X[i]+L[i];
    }
    sort(v.begin(),v.end(),comp);
    long int ans=1,rr=v[0].second;
    for (int i=1;i<N;i++){
        if (rr<=v[i].first){
            ans++;
            rr=v[i].second;
        }
    }
    cout<<ans<<endl;
}