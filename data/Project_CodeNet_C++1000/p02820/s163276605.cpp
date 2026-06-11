#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <iomanip>
#include <numeric>
 
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
string S,T;
vector<ll> so;


ll N,K,M;
ll r,s,p;
ll ans[100005][2];
ll TT[100005];

ll lmax(ll a,ll b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}
int main() {
    cin >> N >> K;
    cin >> r >> s >> p;
    cin >> T;
    for(ll i=0;i<N;i++){
        if(T[i]=='r'){
            TT[i] = p;
        }
        if(T[i]=='s'){
            TT[i] = r;
        }
        if(T[i]=='p'){
            TT[i] = s;
        }
    }
    ll k=0;
    for(ll i=0;i<K;i++){
        if(i==0){
            ans[k][0] = 0;
            ans[k][1] = TT[i];
        }else{
            ans[k][0] = lmax(ans[k-1][1],ans[k-1][0]);
            ans[k][1] = lmax(ans[k-1][1],ans[k-1][0])+TT[i];
        }
        k++;
        for(ll j=i+K;j<N;j+=K){
            if(T[j]==T[j-K]){
                ans[k][1] = ans[k-1][0] + TT[j];
            }else{
                ans[k][1] = lmax(ans[k-1][1],ans[k-1][0]) + TT[j];
            }
            ans[k][0] = lmax(ans[k-1][1],ans[k-1][0]);
            k++;
        }
    }
    cout << lmax(ans[N-1][0],ans[N-1][1]) << endl;
    
}
