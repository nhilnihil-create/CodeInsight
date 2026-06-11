#include <iostream>
#include <vector>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
using ll = long long;

using namespace std;



int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> res(n+1, vector<int>(2));
    rep(i,m) {
        int p;
        string s;
        cin >> p >> s;
        if(res[p][0]) continue;
        if(s == "AC") res[p][0] = 1;
        else res[p][1]++;
    }
    int ac = 0, wa = 0;
    rrep(i,n) {
        ac += res[i][0];
        if(res[i][0]) wa += res[i][1];
    }
    cout << ac << " " << wa << endl;

    return 0;
}
