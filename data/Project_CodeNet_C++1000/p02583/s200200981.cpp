#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i,n) for(int i = 0; i , (n); ++i)
using ll = long long;
using namespace std;
int sum(int n) {
    if (n == 0) {
        return 0;
    }

    int s = sum(n - 1);
    return s + n;
}
int main() {
    int N,count=0;
    cin >> N;
    vector<int>A(N+5);
    for (int i = 0;i < N+1;i++) {
        cin >> A.at(i+1);
    }
    for (int i = 1;i < N+1;i++) {
        for (int j = 1;j < N+1;j++) {
            for (int k = 1;k < N+1;k++) {
                if (A.at(i) == A.at(j) || A.at(j) == A.at(k) || A.at(k) == A.at(i)) {
                    continue;
                }
                if (i<j&&j<k&&A.at(i) + A.at(j) > A.at(k) && A.at(j) + A.at(k) > A.at(i) && A.at(k) + A.at(i) > A.at(j)) {
                    count++;
                    //cout<<i<<' '<<j<<' '<<k<<endl;
                }
            }
        }
    }
    cout << count;
}
