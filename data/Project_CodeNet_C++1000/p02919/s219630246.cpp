#include <bits/stdc++.h>

#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    using namespace std;
    ll n;
    cin >> n;
    vector<int> A(n + 2);
    A[0] = n + 1;
    A[n + 1] = n + 2;
    for(int i = 1; i < n + 1; i++)
        cin >> A[i];
    vector<int> next(n + 2),
                nnext(n + 2, -1),
                prev(n + 2),
                nprev(n + 2, -1);
    stack<int> B;
    priority_queue< pair<int, int> > D;
    for(int i = 1; i < n + 2; i++) {
        while(D.size() > 0 && -D.top().first < A[i]) {
            nnext[D.top().second] = i;
            D.pop();
        }
        while(B.size() > 0 && A[B.top()] < A[i]) {
            next[B.top()] = i;
            D.push(make_pair(-A[B.top()], B.top()));
            B.pop();
        }
        B.push(i);
    }
    while(B.size()) B.pop();
    while(D.size()) D.pop();
    for(int i = n; i >= 0; i--) {
        while(D.size() > 0 && -D.top().first < A[i]) {
            nprev[D.top().second] = i;
            D.pop();
        }
        while(B.size() > 0 && A[B.top()] < A[i]) {
            prev[B.top()] = i;
            D.push(make_pair(-A[B.top()], B.top()));
            B.pop();
        }
        B.push(i);
    }

#if 0
    for(int i = 0; i < n + 2; i++)
        cout << A[i] << " \n"[i == n + 1];
    for(int i = 0; i < n + 2; i++)
        cout << next[i] << " \n"[i == n + 1];
    cout << "\n\n";
    for(int i = 0; i < n + 2; i++)
        cout << prev[i] << " \n"[i == n + 1];
    cout << "\n\n";
#endif

    ll result = 0;
    for(int i = 1; i < n + 1; i++) {
        if(nprev[i] != -1)
            result += (ll)A[i] * (prev[i] - nprev[i]) * (next[i] - i);
        if(nnext[i] != -1)
            result += (ll)A[i] * (nnext[i] - next[i]) * (i - prev[i]);
    }
    cout << result << "\n";
    return 0;
}
