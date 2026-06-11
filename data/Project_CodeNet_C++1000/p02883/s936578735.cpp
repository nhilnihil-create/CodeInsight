#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int N,K,u=1e18,l=-1;
    cin >> N >> K;

    vector<long long int> A(N),F(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
    }

    for(int i=0;i<N;i++){
        cin >> F[i];
    }

    sort(A.begin(),A.end());
    sort(F.begin(),F.end());

    while(1<u-l){
        long long int mid = (u+l)/2,move=0;

        for(int i=0;i<N;i++){
            long long int tmp = A[i]*F[N-1-i] - mid;
            if(0<tmp){
                move += (tmp+F[N-1-i]-1)/F[N-1-i];
            }
        }

        if(K<move){
            l = mid;
        }else{
            u = mid;
        }
    }

    cout << u << endl;
}