#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(void){
    int N;
    cin >> N;
    int d[N];
    for(int i=0;i<N;i++){
        cin >> d[i];
    }
    sort(d,d+N);
    int L,H;
    L = d[N/2-1];
    H = d[N/2];
    int ans = H - L;
    cout << ans;
}
