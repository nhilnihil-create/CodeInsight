#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

#define FOR(N) for(int i=0;i<N;i++)

int main(){
    long long K=3,N,x,max=0,num=7;
    cin >> N;
    vector<long>A(N);
    FOR(N){
        cin >> A[i];
    }
    sort(A.rbegin(),A.rend());
    if((N-1)%2==0){
        max = A[0];
        for(int i=1;i<(N-1)/2;i++){
            max += 2*A[i];
        }
        max += A[(N-1)/2];
    }else{
        max = A[0];
        for(int i=1;i<N/2;i++){
            max += 2*A[i];
        }
    }
    cout << max;

}