#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

long long N;
long long U[220000];
long long V[220000];

int main(void){

    cin >> N;

    for (int i = 1;i <= N - 1;i++) {
        cin >> U[i] >> V[i];
    }

    long long A[N+1];
    for (int i = 1;i <= N;i++) {
        A[i] = 0;
    }

    long long Delv = 0;

    for (int i = 1;i <= N - 1;i++) {
        if(U[i] < V[i]){
            Delv += N + 1 - V[i];
            A[U[i]] += N + 1 - V[i];
        } else {
            Delv += N + 1 - U[i];
            A[V[i]] += N + 1 - U[i];
        }
    }

    long long ans = 0;

    for (int i = 1;i <= N;i++){
        ans += (N + 1 - i) * (N + 2 - i) / 2 - Delv;
        Delv -= A[i];
    }

    cout << ans << endl;

    return 0;
}
