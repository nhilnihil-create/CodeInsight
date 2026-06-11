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

int main(){
    int a;
    cin >> a;
    int n = a;
    int ans = 0;
    rep(i, 3){
        ans += n;
        n *= a;
    }
    cout << ans << endl;
}