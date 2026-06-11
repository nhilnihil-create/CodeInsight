#include <bits/stdc++.h>
using namespace std;
int main() {

    int N;
    cin >> N;
    int A[N+1],B[N+1];
    int C[N];
    for(int i=1;i<=N;i++)cin >> A[i];
    for(int i=1;i<=N;i++)cin >> B[i];
    for(int i=1;i<N;i++)cin >> C[i];
    int Ans =B[A[1]];
    for(int i=2;i<=N;i++){
        Ans+=B[A[i]];
        if(A[i-1]+1==A[i])Ans+=C[A[i-1]];
    }
    cout << Ans << endl;
}
