#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>   // popen, pclose, fgets
#include <cstdlib> 
using namespace std;
#define rep0(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using vi = vector<int>; // intの1次元の型に vi という別名をつける
using vvi = vector<vi>; // intの2次元の型に vvi という別名をつける
using vvvi = vector<vvi>;
using ll = long long; //10e19までいける
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll =vector<vvll>;
const double PI=3.14159265358979323846;
//小数点以下を指定したい時　　→→→→  cout << fixed << setprecision()<<答え<<endl;
//int→string
//string→int   int num = atoi(numStr.c_str());

int main() {
    int n;cin>>n;
    vi v(n);
    rep0(i,n){
        cin>>v[i];
    }
    sort(all(v));
    int ans = v[n/2]-v[n/2-1];
    cout<<ans<<endl;
}