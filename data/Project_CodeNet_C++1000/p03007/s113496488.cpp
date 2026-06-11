//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;
using ll = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;


int main() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int> > Ap;
    priority_queue<int> Am;
    rep(i, n) {
        int a;
        scanf("%d", &a);
        if(a<0) {
            Am.push(a);
        } else {
            Ap.push(a);
        }
    }
    if(!Ap.size()) {
        Ap.push(Am.top());
        Am.pop();
    }
    if(!Am.size()) {
        Am.push(Ap.top());
        Ap.pop();
    }

    vi vecx(n-1), vecy(n-1);
    int i=0;
    while(Ap.size() != 1) {
        vecx[i] = Am.top();
        vecy[i] = Ap.top();
        Am.pop();
        Ap.pop();
        Am.push(vecx[i]-vecy[i]);
        ++i;
    }
    while(Am.size() != 1) {
        vecx[i] = Ap.top();
        vecy[i] = Am.top();
        Ap.pop();
        Am.pop();
        Ap.push(vecx[i]-vecy[i]);
        ++i;
    }
    cout << Ap.top()-Am.top() << '\n';
    rep(i, n-2) {
        cout << vecx[i] << ' ' << vecy[i] << '\n';
    }
    cout << Ap.top() << ' ' << Am.top() << '\n';
}