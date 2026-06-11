#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); i++)
using namespace std;
using ll = long long;
typedef pair<int,int> P;

int main(void) {
    int N; cin >> N;
    for(int i=0; i<N; i++) {
        int A; cin >> A;
        if(A%2==0) {
            if(A%3!=0 && A%5!=0) {
                cout << "DENIED" << endl;
                return 0;
            }
        }
    }
    cout << "APPROVED" << endl;
    return 0;
}