#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> A(N);
    for(auto&& x:A)cin >> x;
    sort(A.begin(), A.end());
    int sum = 0;
    for(int i=1;i<N-1;i++)sum += abs(A[i]);
    cout << A[N-1] + sum - A[0] << endl;
    for(int i=1;i<N-1;i++){
        if(A[i] < 0){
            cout << A[N-1] << " " << A[i] << endl;
            A[N-1] -= A[i];
        }else{
            cout << A[0] << " " << A[i] << endl;
            A[0] -= A[i];
        }
    }
    cout << A[N-1] << " " << A[0] << endl;
    return 0;
}