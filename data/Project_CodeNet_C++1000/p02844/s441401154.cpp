#include<bits//stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int n, ans = 0; string s,t="810";
vector<char> c = { '0','1','2','3','4','5','6','7','8','9' };
void dfs(int i) {
    if (i == 3) {
        int id = 0;
        rep(l, n) {
            if (s[l] == t[id]) id++;
            if (id > 2) {
                ans++; break;
            }
        }
    }
    else {
        rep(j, 10) {
            t[i] = c[j];dfs(i+1);
        }
    }
}
int main() {
    cin >>n >>s; dfs(0); cout << ans << endl;
}