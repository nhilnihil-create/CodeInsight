#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long long> A(N), B(N);
    for(int i=0;i<N;++i) cin >> A[i] >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    long long ans = 0;

    // 奇数
    if(N % 2){
        ans = B[N / 2] - A[N/2] + 1;
    }
    else{
        long long a = A[N/2 - 1] + A[N/2];
        long long b = B[N/2 - 1] + B[N/2];
        ans = b - a + 1;
    }
    if(ans < 0) ans = 0;
    cout << ans << endl;
}
