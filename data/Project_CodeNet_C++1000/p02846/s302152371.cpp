#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int T[2];
    cin >> T[0] >> T[1];
    long A[2], B[2];
    cin >> A[0] >> A[1];
    cin >> B[0] >> B[1];

    long g[2];
    for(int i=0; i<2; i++){
        g[i] = (A[i] - B[i]) * T[i];
    }


    if(g[0] + g[1] == 0){
        cout << "infinity" << endl;
        return 0;
    }

    if( (g[0] > 0 && g[0] + g[1] > 0) || (g[0] < 0 && g[0] + g[1] < 0)){
        cout << 0 << endl;
        return 0;
    }

    long d = g[0] + g[1];

    long ans = abs(g[0]) / abs(d) * 2;
    if(abs(g[0]) % abs(d) != 0){
        ans++;
    }

    cout << ans << endl;
    return 0;
}