#include<bits/stdc++.h>
using namespace std;

int main(){
    long long N, stock, yen  = 1000, input;
    vector<int> A;
    cin>>N;

    for(int i=0; i<N;i++){
        cin>>input;
        A.push_back(input);
    }
    for(int i=0; i<N;i++){
        stock = 0;
        if(A[i] < A[i+1])
            stock = yen/A[i];
        yen += (A[i+1] - A[i])*stock;
    }
    cout<<yen<<endl;

    return 0;
}
