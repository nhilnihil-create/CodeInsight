#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    int N;
    cin >> N;
    int W[N+1];
    for(int i=1;i<=N;i++)cin >> W[i];
    
    int ans = 1000000;
    for(int T=1;T<N;T++){
        int S1=0,S2=0;
        for(int i=1;i<=N;i++){
            if(i <= T)S1+=W[i];
            else S2+=W[i];
        }
        ans = min(ans,abs(S1-S2));
    }
    cout << ans;
    
}
