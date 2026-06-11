/*
 
dunjen_master
 
*/
 
 
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
 
#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
 
using namespace std;
 
const int MAX_N = int(1e6) + 10;
const long long int MOD=1e9+7;
const long long int INF=1e18;
 
typedef long long int ll;
typedef unsigned long long int llu;
 
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>

inline ll mul(ll a,ll b){

    a=(a+MOD)%MOD;
    b=(b+MOD)%MOD;
    ll c=a*b;
    c=(c+MOD)%MOD;
    return c;
}
inline ll add(ll a,ll b){
    a=(a+MOD)%MOD;
    b=(b+MOD)%MOD;
    ll ans=(a+b);
    ans=(ans+MOD)%MOD;
    return ans;
}
ll power(ll a,ll b,ll c=0){
    ll ans=1;
    while(b){
        if(b&1){
            ans=mul(ans,a);
        }
        a=mul(a,a);
        b=b/2;
    }
    return ans;
}
template<class T1, class T2>
istream &operator>>(istream &in, pair<T1, T2> &P){
    in >> P.first >> P.second;
    return in;
}
 
template<class T1, class T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &P){
    out << "(" << P.first << ", " << P.second << ")";
    return out;
}
template<class T>
istream &operator>>(istream &in, vector<T> &arr){
    for(auto &x: arr) in >> x;
    return in;
}
template<class T>
ostream &operator<<(ostream &out, const vector<T> &arr){
    for(auto &x: arr) out << x << ' '; cout << "\n";
    return out;
}
template<class T>
istream &operator>>(istream &in, deque<T> &arr){
    for(auto &x: arr) in >> x;
    return in;
}
template<class T>
ostream &operator<<(ostream &out, const deque<T> &arr){
    for(auto &x: arr) out << x << ' '; cout << "\n";
    return out;
}
mt19937 rnd(time(0));
 
inline ll gcd(ll a,ll b){
    while(b)a%=b,swap(a,b);
    return a;
}
  

 
#define all(x) (x).begin(),(x).end()

/* ordered_set A;
   A.insert(x);
   A.erase(x);
   A.order_of_key(x) // no of elements less than (<) x
   *A.find_by_order(k-1) // kth smallest element
*/
int n;
int k;
int c;
int earliest[200005];
int latest[200005];
string s;

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);



    cin>>n>>k>>c;

    fill(latest,latest+k,-1);
    fill(earliest,earliest+k,-1);

    cin>>s;


    int i=0;
    int j=0;

    while(i<n){
        if(s[i]=='o' && j<k){
            earliest[j++]=i;
            i+=c+1;
        }else{
            i++;
        }
    }

    i=n-1;
    j=k-1;

    while(i>=0){
        if(s[i]=='o' && j>=0){
            latest[j--]=i;
            i-=c;
        }

        i--;
    }

    for(int i=0;i<k;i++){
        if(latest[i]==earliest[i]){
            cout<<latest[i]+1<<" ";
        }
    }




    

    




    


    
    
    
    
 
    
}

    

    
 
    

