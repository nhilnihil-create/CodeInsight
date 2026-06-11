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
    string s, t;
    cin >> s >> t;
    int ans = 0;
    rep(i, s.size()){
        if(s[i] != t[i]){
            ans++;
        }
    }
    cout << ans << endl;
}