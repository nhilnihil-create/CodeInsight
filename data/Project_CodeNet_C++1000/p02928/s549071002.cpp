
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;
    
    vector<int> A(n);
    vector<int> Acnt(2001,0);
    for (int i = 0; i < n; i++){
        cin >> A.at(i);
        Acnt[A[i]]++;
    }

    long long ans1=0;
    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            if(A[i]>A[j]){
                ans1=(ans1+k)%(7+(long long)1e9);
            }
        }
    }
    long long temp=0;
    long long ans2=0;
    long long kk;

    if(k%2==0){
        kk=((k/2)*(k-1))%(7+(long long)1e9);
    }
    else{
        kk=(k*((k-1)/2))%(7+(long long)1e9);
    }
    for (int i = 1; i < 2001; i++){
        if(Acnt[i]!=0){
            ans2=ans2+temp*Acnt[i];
            temp=temp+Acnt[i];
        }
    }
    ans2=(ans2*kk)%(7+(long long)1e9);
    
    cout << (ans1+ans2)%(7+(long long)1e9) << endl;
}