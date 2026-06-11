#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    int N;
    cin >> N;
    vector<long long> A(N);
    for(int i=0;i<N;i++)
        cin >> A[i];

    for(int i=0;i<N;i++){
        if(A[i] == 0){
            cout << 0;
            return 0;
        }
    }

    long long MAX = pow(10,18);
    int keta1=0,keta2=0;
    long long res = 1;
    for(int i=0;i<N;i++){
        keta1 = log10(res);
        keta2 = log10(A[i]);
        res *= A[i];
        if(((keta1 + keta2 >= 18) && (res != MAX)) || (res > MAX)){
            res = -1;
            break;
        }
    }

    cout << res;
    return 0; 
}