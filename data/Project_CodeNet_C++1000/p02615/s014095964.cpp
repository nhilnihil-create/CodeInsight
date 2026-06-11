#include <iostream>
#include "algorithm"
typedef long long ll;
using namespace std;
ll A[200050];
bool cmp(ll a,ll b){
	return a>b;
}
int main() {
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A,A+N,cmp);

    ll res = A[0];
    int number = 2;
    for (int i = 1; number<N ; i++ ) {
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
