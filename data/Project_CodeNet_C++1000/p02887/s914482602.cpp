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
    string s;
    cin >> n >> s;
    int ans = 1;
    rep(i, n - 1){
        if(s[i] != s[i+1]) ans++;
    }
    cout << ans << endl;
}