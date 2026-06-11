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
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    rep(i, n/2){
        if(s[i] != s[n-1-i]){
            ans++;
        }
    }
    cout << ans << endl;
}