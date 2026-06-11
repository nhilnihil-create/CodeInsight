#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print_vector(vector<T>& vec) {
    cout << "print_vector -> ";
    for(int i=0; i<vec.size(); i++) {
        if(i == vec.size()-1) {
            cout << vec[i] << endl;
        }
        else {
            cout << vec[i] << " ";
        }
    }
    return;
}

int n, m, q;

vector<int> a;
vector<int> b;
vector<int> c;
vector<int> d;

void dfs(vector<int> A, unsigned long long *ans) {

    if(A.size() == n+1) {

        unsigned long long temp_ans = 0;
        for(int i=0; i<q; i++) {
            if(A[b[i]] - A[a[i]] == c[i]) temp_ans += d[i];
        }
        if(temp_ans > *ans) {
            *ans = temp_ans;
        }

        return;
    }

    A.push_back(A.back());
    while(A.back() <= m) {
        dfs(A, ans);
        A.back()++;
    }

}

int main() {

    cin >> n >> m >> q;

    a.resize(q);
    b.resize(q);
    c.resize(q);
    d.resize(q);
    for(int i=0; i<q; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    
    unsigned long long ans = 0;
    dfs(vector<int>(1,1), &ans);
    cout << ans << endl;
    
    return 0;
}