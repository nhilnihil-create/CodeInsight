#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 100;
const long int Max = pow(10, 10);

int setmatrixmulti(int p[], int n){
    int m[N+1][N+1];
    int minval;
    for(int l=1; l<=n; l++){
        for(int i=1; i<=n - l + 1; i++){
            int j = i + l - 1;
            m[i][j] = Max;
            if(i == j){
                m[i][j] = 0;
            } else {
                for(int k=i; k<j; k++){
                    m[i][j] = min(m[i][j], m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]);
                }
            }
        }
    }
    minval= m[1][n];
    return minval;
}

int main(){
    int n, p1, p2;
    cin >> n;
    int p[n+1];
    for(int i=0; i<n; i++){
        cin >> p1 >> p2;
        if(i == 0){
            p[i] = p1;
            p[i+1] = p2;
        } else {
            p[i+1] = p2;
        }
    }

    // for(int i=0; i<n+1; i++){
    //     cout << p[i] << " " ;
    // }

    int ans = setmatrixmulti(p, n);
    cout << ans << endl;

    return 0;
}
