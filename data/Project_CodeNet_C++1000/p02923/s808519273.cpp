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
    int h[n];
    rep(i, n) cin >> h[i];
    int ans = 0;
    int num = 0;
    rep(i, n - 1){
        if(h[i] >= h[i+1]){
            num++;
        }else{
            ans = max(num, ans);
            num = 0;
        }
    }
    ans = max(num, ans);
    cout << ans << endl;
}