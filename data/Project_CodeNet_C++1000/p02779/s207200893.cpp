#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    cin >> N;
    long long int A[N];
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    sort(A,A+N);
    for(int i=0;i<N;i++){
        if(A[i]==A[i+1]){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}