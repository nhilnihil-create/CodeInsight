#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000001
//0=48,A=65,a=97

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<vector<bool>> l(n, vector<bool>(10, false)),r(n, vector<bool>(10, false));
    for(int i = 1; i < n-1; i++) {
        l[i]=l[i-1];
        l[i][(int)s[i-1]-48]=true;
    }
    for(int i = n-2; i >=1; i--) {
        r[i]=r[i+1];
        r[i][(int)s[i+1]-48]=true;
    }

    vector<set<int>> a(10);
    for(int i = 1; i < n-1; i++) {
        int m=(int)s[i]-48;
        for(int j = 0; j < 10; j++) {
            for(int k = 0; k < 10; k++) {
                if(l[i][j] && r[i][k]){
                    a[m].insert(j*10+k);
                }
            }
        }
    }

    int ans=0;
    for(int i = 0; i < 10; i++) {
        ans += a[i].size();
    }
    cout << ans << endl;

    return 0;
}