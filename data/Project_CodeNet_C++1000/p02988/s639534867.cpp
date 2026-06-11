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
    rep(i, n) cin >> p[i];
    int ans = 0;
    rep(i, n - 2){
        vec num;
        rep(j, 3){
            num.push_back(p[i+j]);
        }
        sort(num.begin(), num.end());
        if(num[1] == p[i+1])ans++;
    }
    cout << ans << endl;
}