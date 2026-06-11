#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<cmath>
using namespace std;

int main(){
    int N;
    int B[200000];
    cin >> N;
    for(int i = 0; i < N - 1; i++){
        cin >> B[i];
    }
    int A[200000];
    A[0] = B[0];
    for(int i = 1; i < N - 1; i++){
        A[i] = min(B[i - 1] , B[i]);
    }
    A[N - 1] = B[N - 2];
    long long ans = 0;
    for(int i = 0; i < N; i++){
        ans += A[i];
    }
    cout << ans << endl;
    return 0;
}