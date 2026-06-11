#include<bits//stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;int a, b,c;a = 0; b = 0;c = 1;
    vector<int> p(n), q(n),v(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i]; v[i] = i + 1;
    }
    for (int i = 0;i < n;i++)cin >> q[i];
    do {
        if (v == q) a = c;
        if (v == p) b = c;
        c++;
    } while (next_permutation(v.begin(),v.end()));
    cout << abs(a - b) << endl;
}
