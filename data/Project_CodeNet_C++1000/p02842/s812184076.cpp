#include <iostream>
using namespace std;
int main(void){
    int N;
    cin >> N;
    int ans = -1;
    for(int i=1;i<=N;i++){
        int M = i * 1.08;
        if(N == M){
            ans = i;
            break;
        }
    }
    if(ans == -1){
        cout << ":(" << endl;
    }
    else{
        cout << ans << endl;
    }
}
