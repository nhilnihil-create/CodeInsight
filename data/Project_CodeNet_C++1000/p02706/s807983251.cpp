#include <iostream>
using namespace std;

int main() {
    int N , M ;
    cin >> N >> M ; 
    int A[M];
    int sum = 0;
    for (int i ; i < M ; i++){
        cin >> A[i];
        sum += A[i];
    }
    if (N >= sum) cout << N - sum << endl ;
    else cout << "-1" <<endl;
	return 0;
}