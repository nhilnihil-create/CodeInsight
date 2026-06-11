#include <iostream>
#include <algorithm>
using namespace std;
int min(int a,int b){
    return a<b?a:b;
}
int main(void){
    int N,K;
    cin >> N >> K;
    int H[N];
    for(int i=0;i<N;i++){
        cin >> H[i];
    }
    long long ans = 0;
    for(int i=0;i<N;i++){
        ans += H[i];
    }
    sort(H,H+N,greater<int>());
    for(int i=0;i<K;i++){
        if(i >= N)break;
        ans -= H[i];
    }
    cout << ans << endl;
}
