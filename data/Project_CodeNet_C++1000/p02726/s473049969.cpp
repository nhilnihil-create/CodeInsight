#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); i++)
using namespace std;
using ll = long long;
typedef pair<int,int> P;

int main(void) {
    int N,X,Y; cin >> N >> X >> Y;
    int A[N+10] = {0};
    for(int i=1; i<=N-1; i++) {
        for(int j=i+1; j<=N; j++) {
          int mm = min({abs(j-i),abs(X-i)+1+abs(j-Y),abs(Y-i)+1+abs(j-X)});
          A[mm]++;
        }
    }
    for(int i=1; i<=N-1; i++) cout << A[i] << endl;
    return 0;
}