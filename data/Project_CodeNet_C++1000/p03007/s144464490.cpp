#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <map>
#include <array>
#include <cmath>
#include <set>
#include <numeric>

using namespace std;

template <typename T>
using TABLE = vector<vector<T>>;

long long PRIME = 1e9 + 7;
long long PRIME2 = 998244353;


int main(){
    long long N;
    cin >> N;

    vector<long long> A(N);
    for(int i = 0; i < N; ++i){
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int pos = 0;
    long long max_num = A[N - 1] - A[0];

    for(int i = 1; i < N - 1; ++i){
        max_num += abs(A[i]);
    }
    cout << max_num << endl;

    long long plus_num = A[N - 1];
    long long minus_num = A[0];

    for(int i = 1; i < N - 1; ++i){
        if(A[i] >= 0){
            cout << minus_num << " " << A[i] << endl;
            minus_num -= A[i];
        }
        else{
            cout << plus_num << " " << A[i] << endl;
            plus_num -= A[i];
        }
    }

    cout << plus_num << " " << minus_num << endl;

}
