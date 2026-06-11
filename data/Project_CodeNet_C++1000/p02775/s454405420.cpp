#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
#define sz(x) ((ll)(x).size())
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define print(x) cout << (x)
#define printl(x) cout << (x) << endl
#define rep(i,a,b) for(ll i=a; i<b; i++)
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vc = vector<char>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using vvc = vector<vector<char>>;
using ll = long long int;

int main(){
    string N; cin >> N;
    ll n = sz(N);
    ll c = 0;
    ll s = 0;
    ll t = 0;
    for(int i=n-1; i>=0; i--){
        int p = N[i] - '0';
        if(i == 0){
            if(p <= 5){
                p += s;
            }else{
                p += s+t;
            }
            if(p <= 5){
                c += p;
            }else{
                c += 11 - p;
            }
        }
        else{
        if(p < 5){
            p += s;
            s = 0; t = 0;
            if(p == 5){
                t++;
            }
        }else if(p == 5){
            p += s + t;
            if(p == 5){
                s = 0;
                t = 1;
            }else{
                s = 1; t = 0;
            }
        }else if(p > 5){
            p += s + t;
            s = 1; t = 0;
        }
        if(p < 5){
            c += p;
        }else{
            c += 10 - p;
        }
        }
    }
    cout << c;
}