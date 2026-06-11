#include <iostream>
#include "algorithm"
using namespace std;
int main() {
    int N;
    cin >> N;
    long long int A[N];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A,A+N);

    long long int res = A[N-1];
    int number = 2;
    for (int i = N-2; number<N ; i-- ) {
        if(number+2<=N) {
            res = res + 2 * A[i];
            number+=2;
        }else{
            res = res + A[i];
            number++;
        }
    }
    cout << res;
    return 0;

}
