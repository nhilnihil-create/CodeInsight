#include<bits/stdc++.h>
using namespace std;
typedef long long tolong;

int main(){
    tolong N = 0;
    tolong ans = 0;
    tolong tmp = 0;
    tolong i;
  
  	cin >> N;
    vector<tolong> A(N,0);
    
    for(i = 0;i < N;i++){
        cin >> A[i];
    }

    for(i = 1;i < N;i++){
        if(A[i - 1] > A[i]){
            tmp = A[i];
            A[i] = A[i - 1];
            ans = ans + A[i] - tmp;
        }
    }

    cout << ans << endl;
}