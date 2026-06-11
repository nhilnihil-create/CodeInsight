#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int N,M,K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    vector<ll> B(M);
    vector<ll> a(N+1);
    vector<ll> b(M+1);
    int best = 0;
    a.at(0) = 0;
    b.at(0) = 0;
    int j = M;
    int buf = 0;
    int va = 0;
    for(int i=0;i<N;i++) {
        cin >> A.at(i);
    }
    for(int i=0; i<M; i++) {
        cin >> B.at(i);
    }
    for(int i=1; i<N+1; i++) {
        a.at(i) = a.at(i-1) + A.at(i-1); 
    }
    for(int i=1; i<M+1; i++) {
        b.at(i) = b.at(i-1) + B.at(i-1);
    }
    for(int i=0;i<=N;i++) {
        if (a.at(i) > K){
            break;
        }

        best = K - a.at(i);

        while(true) {
            if (j==0) {
                break;
            }
            if (b.at(j) <= best) {
                break;
            }
            j--;
        }
        buf = max(buf,i+j);
    }
    cout << buf << endl;
}