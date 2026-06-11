#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); i++)
using namespace std;
using ll = long long;
typedef pair<int,int> P;

int main(void) {
    int K,N; cin >> K >> N;
    vector<int> A;
    for(int i=0; i<N; i++) {
        int x; cin >> x;
        A.push_back(x); 
    }
    int max_dis=A[0]+K-A[N-1];
    for(int i=1; i<N; i++) {
        int dis = A[i] - A[i-1];
        if(max_dis<dis) max_dis=dis;
    }
    cout << K-max_dis << endl;
    return 0;
}