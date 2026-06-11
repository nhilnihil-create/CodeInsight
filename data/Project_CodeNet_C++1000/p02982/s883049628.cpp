#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <math.h>
#include <sstream>
#include <numeric>
#include <cctype>
#include <bitset>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define SIZE 100005
#define INF 1000000000000000LL
using pint = pair<int,int>;
using vec = vector<int>;
using ll=long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,d;cin>>n>>d;
    vector<vector<int>> a(n,vector<int> (d));

    for(int i=0; i<n; i++){
        for(int j=0; j<d; j++){
            cin>>a[i][j];
        }
    }

    int cnt=0;
    for(int i=0; i<n; i++){
        for(int k=1+i; k<n; k++){
            float ans=0;
            for(int j=0; j<d; j++){
                ans += (a[i][j]-a[k][j])*(a[i][j]-a[k][j]);
            }
            ans=sqrt(ans);
            if(ans==(int)ans) cnt++;
            int b=0;
        }
    }
    
    cout<<cnt<<endl;
    return 0;
}