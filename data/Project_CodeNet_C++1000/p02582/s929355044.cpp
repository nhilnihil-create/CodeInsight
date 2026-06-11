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
    string s;
    cin >> s;
    int ans = 0;
    int now = 0;
    rep(i, 3){
        if(s[i] == 'R'){
            now++;
        }else if(s[i] == 'S'){
            now = 0;
        }
        ans = max(now, ans);
    }
    cout << ans << endl;
}