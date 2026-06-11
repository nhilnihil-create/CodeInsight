#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<cstdio>
#include<map>

using namespace std;

#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<int, int>

typedef vector<int> vec;
typedef vector<vec> mat;

const ll mod = 1000000007;

int main(){
    int a[3];
    rep(i, 3) cin >> a[i];
    if(a[0]+a[1]+a[2] >= 22) cout << "bust" << endl;
    else cout << "win" << endl;
}