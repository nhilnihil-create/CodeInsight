#include <bits/stdc++.h>
using namespace std;

int main(){
    int A,B,M; cin >> A >> B >> M;
    vector<int> a(A),b(B),x(M),y(M),c(M);
    for(int i = 0; i < A; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < B; i++) {
        cin >> b[i];
    }
    int cost=INT_MAX;
    for(int i = 0; i < M; i++) {
        cin >> x[i] >> y[i] >> c[i];
        cost = min(cost,a[x[i]-1]+b[y[i]-1]-c[i]);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    cost = min(cost, a[0]+b[0]);
    cout << cost << endl;
    return 0;
}