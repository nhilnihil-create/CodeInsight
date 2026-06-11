#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    int N;
    cin>>N;
    vector<int> A(N),B(N);
    for (int i = 0; i < N; i++){
        cin>>A[i]>>B[i];
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    if(N%2==1){
        int m=(N+1)/2-1;
        cout<<B[m]-A[m]+1<<endl;
    }else{
        int m=N/2-1;
        cout<<B[m]+B[m+1]-A[m]-A[m+1]+1<<endl;
    }

}