#include <bits/stdc++.h>
using namespace std;
int main(){
    int K;
    cin >> K;
    int N;
    cin  >> N; 
    int A[N];
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    int  m=0;
    for(int i=0;i<N-1;i++){
        m = max(m,A[i+1]-A[i]);
    }
    m=max(m,K+A[0]-A[N-1]);
    int Ans = K-m;
    cout << Ans << endl;
}
