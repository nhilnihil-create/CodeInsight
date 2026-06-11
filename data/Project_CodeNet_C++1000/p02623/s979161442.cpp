#include <vector>
#include <stack>
#include <iostream>
#include <bitset>

using namespace std;

#define MAX_N 200000
#define MAX_M 200000

int N, M, K;
int64_t A[MAX_N+1], a[MAX_N+1];
int64_t B[MAX_M+1], b[MAX_M+1];

void input() {
    a[0]=0;
    b[0]=0;
    A[0]=0;
    B[0]=0;
    cin >> N >> M >> K;
    for (int i=0;i<N;i++) {
        cin>>A[i+1];
        a[i+1]=A[i+1]+a[i];
    }
    for (int i=0;i<M;i++) {
        cin>>B[i+1];
        b[i+1]=B[i+1]+b[i];
    }
}

void solve() {
    //A[0]~A[i]の和a[i]
    //B[0]~B[j]の和b[i]
    //a[i]+b[j]<=K min? の条件下でi+jを最大とする。
    int ans = 0;
    int j = M;
    for (int i=0;i<N+1;i++){
        if (a[i]>K){
            break;
        }
        while (b[j] > K-a[i]){
            j--;
        }
        ans = max(ans,i+j);
    }
    cout << ans << endl;
}

int main()
{
    input();
    solve();
    return 0;
}