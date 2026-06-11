#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
typedef pair<int,int> P;
int main() {
    int N,K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, 0, N){
        cin >> A[i];
    }
    rep(ki, 0, K){
        vector<int> B(N+1);
        rep(i, 0, N){
            int l = max(0, i-A[i]);
            int r = min(N, i+A[i]+1);
            
            B[l]++;
            B[r]--;
        }
        rep(i, 0, N){
            B[i+1] += B[i];
        }
        B.pop_back();
        if(A == B) break;
        A = B;
    }
    
    rep(i, 0, N){
        cout << A[i] << " ";
    }
    return 0;
}
