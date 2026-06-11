#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    int N, M;
    int64_t K;

    cin >> N >> M >> K;

    int64_t A[N];
    int64_t B[M];

    for ( int i = 0; i < N; i ++ ) {
        cin >> A[i];
     }
    for ( int i = 0; i < M; i ++ ) {
        cin >> B[i];
    }

    vector <int64_t> sumA( N+1, 0 ), sumB( M+1, 0 );
    for ( int i = 1; i <= N; i ++ ) sumA[i] = sumA[i-1] + A[i-1];
    for ( int i = 1; i <= M; i ++ ) sumB[i] = sumB[i-1] + B[i-1];

/*
    for ( int i = 0; i < N+1; i ++ ) cout << sumA[i] << " ";
    cout << endl;
    for ( int i = 0; i < M+1; i ++ ) cout << sumB[i] << " ";
    cout << endl;
*/

    int maxcount = 0;
    int n = 0;
    int m = M;
    for ( n = 0; n <= N; n ++ ) {
        if ( K < sumA[n] ) break;
        // cout << " test A " << n << " sum:" << sumA[n] << " remain " << K-sumA[n] << endl;
        while ( K - sumA[n] < sumB[m] ) m --;
        // cout << "   test B " << m << " sumB: " << sumB[m] << " total " << sumA[n] + sumB[m] << endl;
        // cout << "   count " << n+m << endl;        

        maxcount = max( maxcount, n+m );        
    }

    cout << maxcount << endl;
    

    return 0;
}