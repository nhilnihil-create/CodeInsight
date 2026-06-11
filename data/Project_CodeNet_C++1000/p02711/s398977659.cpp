#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); i++)
using namespace std;
using ll = long long;
typedef pair<int,int> P;

int main(void) {
    int N; cin >> N;
    while(N) {
        int x = N%10;
        if(x==7) {
            cout << "Yes" << endl;
            return 0;
        }
        N/=10;
    }
    cout << "No" << endl;
}