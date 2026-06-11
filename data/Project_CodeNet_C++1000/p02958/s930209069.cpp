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
    int n;
    cin >> n;
    int p[n];
    int copy[n];
    rep(i, n) {
        cin >> p[i];
        copy[i] = p[i];
    }

    sort(p, p + n);
    int num = 0;
    rep(i, n){
        if(p[i] != copy[i]) num++;
    }
    if(num <= 2) cout << "YES" << endl;
    else cout << "NO" << endl;
}