#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <queue>
#include <iomanip>
#include <set>
//#include <bits/stdc++.h>
template<typename T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}
using namespace std;
#define ALL(X) X.begin(),X.end()
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
const int MOD=1000000007;
//const int MOD=998244353;
const int INTMAX=2147483647;
const ll LLMAX=9223372036854775807;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N;
    cin>>N;
    
    vll A(N+1);
    for(ll i=0;i<=N;i++)cin>>A[i];
    if(N==0){
        if(A[0]==1){
            cout<<1<<endl;
            return 0;
        }else {
            cout<<-1<<endl;
            return 0;
        }
    }
    if(A[0]!=0){
        cout<<-1<<endl;
        return 0;
    }
    
    
    vll B(N+1);
    for(ll i=0;i<=N;i++){
        if(i==0){
            B[0]=1;
        }else{
            if(B[i-1]>100000000000000000)B[i]=100000000000000001;
            else B[i]=(B[i-1]-A[i-1])*2;
            
            if(B[i]<A[i]){
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    
    vll C(N+1);
    for(ll i=N;i>=0;i--){
        if(i==N){
            C[i]=A[i];
        }else{
            C[i]=C[i+1]+A[i];
        }
    }
    
    ll ans=0;
    for(ll i=0;i<=N;i++){ans+=min(B[i],C[i]);
    }
    cout<<ans<<endl;
    
    return 0;
}
