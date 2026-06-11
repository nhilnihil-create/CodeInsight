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

const ll mod = 1000000007;

int main(){
    int n, k, q;
    cin >> n >> k >> q;
    int a[q];
    rep(i, q){
        cin >> a[i];
        a[i]--;
    }
    int p[n];
    fill(p, p + n, 0);
    rep(i, q){
        p[a[i]]++;
    }
    rep(i, n){
        if(k - q + p[i] > 0){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl; 
        }
    }
    // rep(i, n){
    //     cout << p[i] << endl;
    // }
}