#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, k;
    while(cin >> n >> k){
        if(!n&&!k) break;
        int A[n]={0}, S[n+1]={0};
        for(int i=0;i<n;i++) {
            cin >> A[i];
            S[i+1] = S[i]+A[i];
        }
        int maxValue = -600000000;
        for(int i=0;i+k<=n;i++){
            maxValue = max(maxValue, S[k+i]-S[i]);
        }
        cout << maxValue << endl;
    }
    //cout << "finished" << endl;
    return 0;
}
