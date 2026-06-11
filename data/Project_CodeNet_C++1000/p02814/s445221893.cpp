#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <cmath>
#include <deque>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <numeric>
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep3(i,a,b) for(int i=a;i>=b;i--)
#define REP(e,v) for(auto e:v)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define mt make_tuple
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define vec vector<int>
#define vecvec vector<vec>
#define vecll vector<ll>
#define vecpii vector<pii>
#define vecpll vector<pll>
#define vecbl vector<bool>
#define endl "\n"
#define ALL(c) (c).begin(),(c).end()
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}
string stin(){string s;cin>>s;return s;}

int cnt2(ll a,int n){
    if(a%2==1)return n;
    return cnt2(a/2,n+1);
}

ll gcd(ll a,ll b){
    if(a<b)return gcd(b,a);
    if(b==0)return a;
    return gcd(b,a%b);
}

ll lcm(ll a,ll b){
    return a*b/gcd(a,b);
}

int main(){
    int n=in(),m=in();
    ll L=1;
    vec a(n);
    int k=-1;
    rep(i,n){
        a[i]=in();
        int x=cnt2(a[i],0);
        if(k==-1)k=x;
        if(k!=x){
            cout<<0<<endl;
            return 0;
        }
        a[i]/=pow(2,k);
        L=lcm(L,a[i]);
        if(L>m){
            cout<<0<<endl;
            return 0;
        }
    }
    cout<<m/(L*(ll)pow(2,k-1))-m/(L*(ll)pow(2,k))<<endl;
}
