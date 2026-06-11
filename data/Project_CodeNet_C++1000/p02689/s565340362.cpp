#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <stdio.h>
#include <set>
#include <iomanip>
using namespace std;
using Graph = vector<vector<int>>;
 
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> H(N);
    vector<int> C(N);
    for (int i=0; i<N; i++){
        cin >> H[i];
        C[i] = true;
    }
    //vector<int> A(M);
    //vector<int> B(M);
    for (int i=0; i<M; i++){
        int a, b;
        //cin >> A[i] >> B[i];
        cin >> a >> b;
        if (H[a-1] >= H[b-1]) C[b-1] = false;
        if (H[a-1] <= H[b-1]) C[a-1] = false;
    }
    int ans = count(C.begin(), C.end(), true);
    cout << ans << endl;
    return 0;
}