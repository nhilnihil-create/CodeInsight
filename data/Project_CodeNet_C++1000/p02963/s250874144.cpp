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
    ll S; cin >> S;
    if(S < 1000000000000000000){
    print(0); print(" ");
    print(0); print(" ");
    print(1000000000); print(" ");
    print(1); print(" ");
    print(1000000000 - S%1000000000); print(" ");
    print((S+(1000000000 - S%1000000000))/1000000000); 
    }
    else{
    print(0); print(" ");
    print(0); print(" ");
    print(1000000000); print(" ");
    print(0); print(" ");
    print(1000000000 - S%1000000000); print(" ");
    print((S+(1000000000 - S%1000000000))/1000000000 - 1); 
    }
}