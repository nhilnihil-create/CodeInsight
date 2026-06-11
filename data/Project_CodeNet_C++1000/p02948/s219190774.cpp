#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<long long, long long> P;
int main(){
    int N, M;
    cin >> N >> M;
    vector<long long> A(N), B(N);
    vector<long long> ind(N);
    set<int> s;
    for(int i = 1; i <= M; i++) s.insert(i);
    for(int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        ind[i] = i;
    }
    sort(ind.begin(), ind.end(), [&](int x, int y){
        if(B[x] != B[y]) return B[x] > B[y];
        return A[x] > A[y];
    });
    long long ans = 0;
    for(int i = 0; i < N; i++){
        auto ite = s.lower_bound(A[ind[i]]);
        if(ite != s.end()){
            ans += B[ind[i]];
            s.erase(*ite);
        }
    }
    cout << ans << endl;
}