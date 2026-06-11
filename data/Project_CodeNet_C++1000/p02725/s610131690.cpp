#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <stdio.h>
#include <set>
#include <iomanip>
using namespace std;
 
int main(){
    int K, N;
    cin >> K >> N;
    vector<int> d(N);
    vector<int> A(N);
    int b;
    int rem = 0;
    cin >> A[0];
    for (int i=1; i<N; i++){
        cin >> A[i];
        d[i-1] = A[i] - A[i-1];
        rem = max(d[i-1], rem);
    }
    d[N-1] = A[0] + (K - A[N-1]);
    rem = max(d[N-1], rem);
    cout << K - rem << endl;
    return 0;
}