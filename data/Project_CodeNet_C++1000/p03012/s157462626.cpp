#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> W(N);
    for(int i = 0; i < N; i++) cin >> W[i];
    int ans = 1e9;
    for(int i = 0; i < N; i++){
        int temp1 = 0, temp2 = 0;
        for(int j = 0; j < N; j++){
            if(j <= i) temp1 += W[j];
            else temp2 += W[j];
        }
        ans = min(ans, abs(temp1 - temp2)) ;
    }
    cout << ans << endl;
}