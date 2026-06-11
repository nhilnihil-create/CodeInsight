#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;
const vi tbl = {1, 1, 2, 6, 24, 120, 720, 5040};

int main(void){
    int n;
    cin >> n;
    vi P(n), Q(n);
    for(int &p : P) cin >> p;
    for(int &q : Q) cin >> q;
    int p = 0, q = 0;
    for(int i=0; i<n-1; i++){
        p += (P[i]-1)*tbl[n-1-i];
        q += (Q[i]-1)*tbl[n-1-i];
        for(int j=i+1; j<n; j++){
            if(P[j]>P[i]) P[j]--;
            if(Q[j]>Q[i]) Q[j]--;
        }
    }
    cout << (p>q?p-q:q-p) << '\n';
    return 0;
}