
#include <iostream>
using namespace std;
int n,m,p;
int X[105];
int main() {
    while(cin >> n >> m >> p, !(n==0 && m==0 && p==0)){
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            X[i] = x;
        }
        int sum=0;
        for(int i=0; i<n; i++){
            sum += X[i];
        }
        int ans;
        if(X[m-1] == 0) ans=0;
        else ans = sum*(100-p)/X[m-1];
        cout << ans << endl;
    }
    return 0;
}