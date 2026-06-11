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
    int n,m;
    int wa[105000];
    bool ac[105000];
    int acnum=0;
    int wanum=0;
    rep(i,n){
        wa[i]=0;
        ac[i]=0;
    }
    cin>>n>>m;
    while(m--){
        int a;
        string b;
        cin>>a>>b;
        if(ac[a])continue;
        if(b=="AC"){
            acnum++;
            wanum+=wa[a];
            ac[a]=1;
        }else{
            wa[a]++;
        }
    }
    
    cout<<acnum<<" "<<wanum<<endl;
    }
