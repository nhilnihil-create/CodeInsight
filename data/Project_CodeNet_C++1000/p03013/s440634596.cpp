#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, m, t;
    cin >> n >> m;
    vector<bool>a(n);
    for(int i=0; i<m; i++){
        cin >> t;
        a[t] = 1;
        if(i!=0&&a[t]==a[t-1]){
            cout << 0 << endl;
            return 0;
        }
    }
    vector<int>F(n+1);
    F[0]=1;
    for(int i=0; i<=n; i++){
        if(a[i]) continue;
        F[i] %= 1000000007;
        F[i+1] += F[i];
        F[i+2] += F[i];
    }
    cout << F[n] << endl;
    return 0;
}