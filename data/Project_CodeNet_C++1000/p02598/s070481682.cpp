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

int n;
int a[200000];
int k;

bool func(int x){
    int res = 0;
    rep(i, n){
        if(a[i] % x == 0){
            res += (a[i] / x) - 1;
        }else{
            res += (a[i] / x);
        }
    }
    if(res <= k) return true;
    else return false;
}

int main(){
    cin >> n >> k;
    rep(i, n) cin >> a[i];
    int l = 1, r = 1000000000;
    while(l < r - 1){
        int mid = (l + r) / 2;
        if(func(mid)) r = mid;
        else l = mid;
    }
    if(func(l)) cout << l << endl;
    else cout << r << endl;
}