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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int score = 0;
    rep(i, n-1){
        if(s[i] == s[i+1]) score++;
    }
    int ans = min(score+2*k, n - 1);
    cout << ans << endl;
    
}