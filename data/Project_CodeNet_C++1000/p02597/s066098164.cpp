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
    int n;
    string s;
    cin >> n >> s;
    int l = 0, r = n - 1;
    int ans = 0;
    while(l < r){
        if(s[l] == 'W' && s[r] == 'R') {
            ans++;
            l++;
            r--;
        }else if(s[l] != 'W') l++;
        else if(s[r] != 'R') r--;
    }
    cout << ans << endl;
}