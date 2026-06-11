#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N;
    cin >> N;
    vector<int64_t> A(N);
    bool zero =false;
    for (int i=0;i<N;i++) {
        cin >> A[i];
        if(A[i]==0){
            zero = true;
        }
    }
    
    
    int64_t ans=1;
    for (int i=0;i<N;i++) {
        if (zero==true) {
            ans = 0;
            break;
        }
        else if(A[i]>1000000000000000000/ans) {
            ans=-1;
            break;
        }
        else {
            ans *= A[i];
        }
    }
    
    cout << ans << endl;
    
}
