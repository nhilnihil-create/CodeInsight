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
    string s, ans;
    cin >> s;
    string a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    a += a;
    rep(i, s.size()){
        rep(j, 26){
            if(s[i] == a[j]){
                ans += a[j+n];
            }
        }
    }
    cout << ans << endl;
}