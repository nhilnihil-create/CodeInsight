#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int ans;
void dfs(vector<int> A, int n, int m, int q, vector<int> a, vector<int> b, vector<int> c, vector<int> d){
    if(A.size() == n) {
        int sum = 0;
        for(int i = 0; i < q; i++) {
            int aa = a.at(i);
            int bb = b.at(i);
            int cc = c.at(i);
            int dd = d.at(i);
            if(A.at(bb) - A.at(aa) == cc) sum += dd;
        }
        ans = max(ans, sum);
        return;
    }
    for(int i = 1; i <= m; i++) {
        if(A.empty()) {
            A.push_back(i);
            dfs(A, n, m, q, a, b, c, d);
        }
        if(A.back() <= i && A.size() < n) {
            A.push_back(i);
            //cout << A.size() << endl;
            dfs(A, n, m, q, a, b, c, d);
            A.pop_back();
        }
    }
}

int main(void){
    int n, m, q;
    vector<int> A = {};
    cin >> n >> m >> q;
    vector<int> a(q),b(q),c(q),d(q);
    for(int i = 0; i < q; i++) {
        cin >> a.at(i) >> b.at(i) >> c.at(i) >> d.at(i);
        a.at(i)--; b.at(i)--;
    }
    dfs(A, n, m, q, a, b, c, d);
    cout << ans << endl;
}
