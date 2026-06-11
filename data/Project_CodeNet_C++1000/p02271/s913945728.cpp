#include<iostream>
#include<vector>
using namespace std;

int can_make(const vector<int>& A, int i, int m, vector<vector<int> >& memo){
    if (m == 0) return 1;
    if (m < 0 || i >= A.size()) return 0;
    if (memo[i][m] != -1) return memo[i][m];
    return memo[i][m] = (can_make(A, i + 1, m, memo) || can_make(A, i + 1, m - A[i], memo));
}

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto& a : A) cin >> a;
    int q;
    cin >> q;
    vector<vector<int> > memo(A.size(), vector<int>(2000, -1));
    for (int i = 0; i < q; i++) {
        int m;
        cin >> m;
        cout << (can_make(A, 0, m, memo) ? "yes" : "no") << endl;
    }
    return 0;
}