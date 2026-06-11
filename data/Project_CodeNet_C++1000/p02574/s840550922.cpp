#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<cstdio>

using namespace std;

#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<int, int>

typedef vector<int> vec;
typedef vector<vec> mat;


int prime[1000001];

bool fact(int x){
    for (int i = 2; i * i <= x; i++){
        if(x % i == 0){
            while(x % i == 0){
                x /= i;
            }
            if(prime[i] != 0) return false;
            prime[i]++;
        }
    }
    if(x != 1){
        if(prime[x] != 0) return false;
        prime[x]++;
    }
    return true;
}

int gcd(int x, int y){
    if(y == 0) return x;
    else return gcd(y, x % y);
}



int main(){
    ll n;
    cin >> n;
    ll a[n];
    rep(i, n) cin >> a[i];
    rep(i, n){
        if(!fact(a[i])) break;
        if(i == n - 1){
            cout << "pairwise coprime" << endl;
            return 0;
        }
    }
    int gcd_ = a[0];
    rep(i, n-1){
        gcd_ = gcd(a[i+1], gcd_);
    }
    if(gcd_ == 1) cout << "setwise coprime" << endl;
    else cout << "not coprime" << endl;

    // rep(i, 6){
    //     cout << prime[i] << endl;
    // }
}