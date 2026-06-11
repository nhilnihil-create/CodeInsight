#include<bits/stdc++.h>
using namespace std;

int main(){

    //n個の整数
    int n; cin >> n;
    //整数
    vector<long long int> A(n);
    for(int i=0; i<n; i++) cin >> A[i];

    //0が含まれるかの確認
    for(int i=0; i<n; i++){
        if(A[i] == 0){
            cout << "0" << endl;
            exit(0);
        }
    }

    long long int ans = 1;
    for(int i=0; i<n; i++){
        if(A[i] > ((long long int)pow(10,18))/ans){
            cout << "-1" << endl;
            exit(0);
        }

        ans *= A[i]; 
    }

    cout << ans << endl;
}