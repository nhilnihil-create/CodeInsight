#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, L, a;
    cin >> N >> L;
    int A[N];
    for (int i=0; i<N; i++) A[i]=L+i;
    int sum=0;
    for (int i=0; i<N; i++){
        sum+=A[i];
    }
    int min_diff=100000000;
    for (int i=0; i<N; i++){
        if (min_diff > abs(sum-(sum-A[i]))){
            min_diff=abs(sum-(sum-A[i]));
            a=sum-A[i];
        }
    }
    cout << a << endl;
}