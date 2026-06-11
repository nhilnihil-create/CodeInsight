#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<long long, long long> P;
int main(){
    int N;
    cin >> N;
    vector<P> A(N);
    for(int i = 0; i < N; i++) {
        long long a, b;
        cin >> a >> b;
        A[i] = P(b, a);
    }
    sort(A.begin(), A.end());
    long long temp = 0;
    for(int i = 0; i < N; i++){
        temp += A[i].second;
        if(temp > A[i].first){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}