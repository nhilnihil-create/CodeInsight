#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> vec(10,vector<int>(10,0));
    for(int i = 1; i <= n; i++) {
        int b = 1;
        while(i/b >= 10) b *= 10;
      if(i/b == 0 || i%10 == 0) continue;
      vec.at(i/b).at(i%10)++;
    }
    long long ans = 0;
    for(int i = 1; i <= 9; i++) {
        for(int j = 1; j <= 9; j++) {
            int a = vec.at(i).at(j);
            int b = vec.at(j).at(i);
            ans += a*b;
        }
    }
    cout << ans << endl;
}
