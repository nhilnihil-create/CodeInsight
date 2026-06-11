#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int A[N];
    for (int i=0; i<N-1; i++) cin >> A[i];
    int ans[N]={0};
    for (int i=0; i<N-1; i++){
        ans[A[i]-1]++;
    }
    for (int x=0; x<N; x++){
        cout << ans[x] << endl;
    }
}