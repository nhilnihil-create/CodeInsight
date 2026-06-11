//おまじない
//#include <bits/stdc++.h>
#include <iostream>
#include<iomanip>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#define INF 1e9+7
#define rep(i,n) for(int i=0;i<n;i++)
#define all(a) a.begin(),a.end()
#define P pair<int,int>
#define space ' '
#define pll pair<ll,ll>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

//(int)'a'は97 (int)'A'は65 (int)'1'は49
//おまじない

const int maxn = 50;

bool compare(pair<ll,ll> a, pair<ll,ll> b){
    if(a.first==b.first)return a.second<b.second;
    else return false;;
}

int main(){
    
    map<pair<ll,ll>,int> m;
    set<pair<ll,ll> > s;
    int n;
    int cnt = 0;
    
    vector<pair<ll,ll> > v(maxn);
    
    cin >> n;
    rep(i,n)cin >> v[i].first>>v[i].second;
    
    sort(v.begin(),v.begin()+n);
    sort(v.begin(),v.begin()+n,compare);
    //reverse(v.begin(),v.begin()+n);
    
    //rep(i,n)cout << v[i].first<<space<<v[i].second<<endl;
    
    //rep(i,n)cout << v[i].first<<space<<v[i].second<<endl;
    
    rep(i,n){
        rep(j,n){
            if(i==j)continue;
            ll a = v[j].first-v[i].first;
            ll b = v[j].second-v[i].second;
            s.insert(make_pair(a,b));
            m[make_pair(a,b)]++;
        }
    }
    
    auto ite = s.begin();
    while(ite!=s.end()){
        if(m[*ite]>cnt)cnt = m[*ite];
        ite++;
    }
    
    cout << n-cnt<<endl;
    
    return 0;
}
