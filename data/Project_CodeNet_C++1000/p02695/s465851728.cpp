#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 15;
const int MAXQ = 55;
int a[MAXQ],b[MAXQ],c[MAXQ],d[MAXQ];
vector<int> A[MAXN];
int N,M,Q; 
int ans = 0;

void dfs(vector<int> &A) {
    // 数列の長さが N に達したら打ち切り
    if (A.size() == N+1) {
        int now = 0;
        // 処理
        for(int i=0; i<Q; i++) {
            if(A[b[i]]-A[a[i]] == c[i]) {
                now += d[i]; 
            }
        }
        ans = std::max(ans,now);
        return;
    }
    int prev_last = (A.empty() ? 1 : A.back());
    for (int v = prev_last; v <= M; ++v) {
        A.push_back(v);
        dfs(A);
        A.pop_back();
    }
}


int main(void){
    // Your code here!
    cin >> N >> M >> Q;
    
    for(int i=0; i<Q; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
    
    vector<int> A;
    dfs(A);
    cout << ans << endl;
}