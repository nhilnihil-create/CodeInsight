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
const int MOD=1000000007;
//const int MOD=998244353;
const int INTMAX=2147483647;
const ll LLMAX=9223372036854775807;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string S;
    cin>>S;
    if(S.size()%2==1){
        cout<<"No"<<endl;
        return 0;
    }
    for(ll i=0;i<S.size();){
        if(S[i]!='h' || S[i+1]!='i'){
            cout<<"No"<<endl;
            return 0;
        }
        i+=2;
    }
    cout<<"Yes"<<endl;
    
    return 0;
}
