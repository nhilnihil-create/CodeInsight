#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 

int main(){
    int N;
    cin>> N;

    vector<int> A(N);
    for(int i=0; i<N; i++){
        cin>>A[i];
    }

    ll CurrentMoney = 1000;
    for(int i=0; i<N-1; i++){
        ll stock = 0;
        if(A[i] < A[i+1]){
            stock = CurrentMoney / A[i];
            CurrentMoney += (A[i+1] - A[i]) * stock;
        } 
    }
    cout<<CurrentMoney<<endl;

    return 0;
}