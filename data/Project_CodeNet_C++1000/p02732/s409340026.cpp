#include <iostream>
#include <vector>
using namespace std;
long long combi(int x){
    return (long long) x*(x-1)/2;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    vector<int> A(N);
    vector<int> cnt(N+1);
    for(int i = 0; i < N; ++i){
        cin >> A[i];
        cnt[A[i]]++;
    }
    long long sum = 0;
    for(int i = 0; i < N; ++i){
        sum += combi(cnt[i+1]);
    }
    for(int i = 0; i < N; ++i){
        cout << sum -(combi(cnt[A[i]]) - combi(cnt[A[i]] - 1)) << endl;
    }
    return 0;
}