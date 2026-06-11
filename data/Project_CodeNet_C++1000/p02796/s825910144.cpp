#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<utility>
#include<cstdio>
#include<set>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include <bitset>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,x,n) for (int i= x;i<n;i++)
#define all(v) v.begin(), v.end()
#define nepe(v) next_permutation(all(v))
using ll = long long;
using vi = vector<int>; 
using vvi = vector<vi>;

typedef pair<int,int> P;
string s;
int k;
ll INF = 10000000000000000;

int main(){
    ll N;
    cin >>N;
    vector<P> arms(N);
    rep(i,N){
        ll x,l;
        cin >>x>>l;
        arms[i] = make_pair(x+l,x-l);
    }
    sort(all(arms));
    ll ans = 1;
    ll end = arms[0].first;
    rep2(i,1,N){
        if(arms[i].second >= end){
            end = arms[i].first;
            ans++;
        }
    }
    cout << ans<<endl;

}