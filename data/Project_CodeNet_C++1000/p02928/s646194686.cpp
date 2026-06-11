#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;
    
    vector<int> A(n);
    for (int i = 0; i < n; i++){
        cin >> A.at(i);
    }

    long long kk;
    if(k%2==0){
        kk=((k/2)*(k-1))%(7+(long long)1e9);
    }
    else{
        kk=(k*((k-1)/2))%(7+(long long)1e9);
    }

    long long ans1=0;
    long long ans2=0;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            if(A[i]>A[j]){
                ans1=(ans1+k)%(7+(long long)1e9);
            }
        }
        for (int j = 0; j < n; j++){
            if(A[i]>A[j]){
                ans2=(ans2+kk)%(7+(long long)1e9);
            }
        }
    }
    
    cout << (ans1+ans2)%(7+(long long)1e9) << endl;
}

