#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
    
int main(){
    int n,k;
    cin >> n >> k;
    vector <int> A(n);
    rep(i,n) cin >> A[i];

    if(n == 1){
        cout << min(n,k) << endl;
    }

    else{
        for(int l=1; l<=min(k,50); l++){
            vector <int> B(n,0);
            for(int i=0; i<n; i++){
                int l = max(0,i-A[i]);
                int r = min(i+A[i],n-1);
                B[l] ++;
                if(r+1<n){
                    B[r+1]--;
                }
            }
    
            for(int i=1; i<n; i++) B[i] += B[i-1];//B complete

            rep(i,n){
                A[i] = B[i];//new A
            }        
        }
    }

    rep(i,n){
        if(i == n-1){
            if(A[i]>n){
                cout << n << endl;
            }
            else{
                cout << A[i] << endl;
            }
        }
        else{
            if(A[i]>n){
                cout << n << endl;
            }
            else{
                cout << A[i] << " ";
            }
        }
    }
}
