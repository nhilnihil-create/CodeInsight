#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    int N,X;
    cin >> N >>X;
    int L[N+1];
    L[0] = 0;
    for(int i=1;i<=N;i++){
        cin >> L[i];
    }
    int ans = 0;
    int D = 0;
    for(int i=0;i<=N;i++){
        D += L[i];
        if(D > X){
            break;
        }
        else{
            ans++;
        }
    }
    
    cout << ans << endl;
}
