#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &a: A) cin >> a;
    vector<int> C(n + 1);
    for (auto &a: A)
        C[a]++;

    priority_queue<int, vector<int>, greater<int>> Q;
    for (auto &c: C){
        if (c > 0)
            Q.push(c);
    }

    vector<int> ans(n + 1);

    for (int i = n; i > 0; i--){
        if (Q.size() < i)
            continue;
        ans[i] = Q.top();
        if (i == 1)
            break;
        int a, b;
        a = Q.top(); Q.pop();
        for (int j = 0; j < a; j++){
            b = Q.top(); Q.pop();
            Q.push(++b);
        }
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << endl;
}