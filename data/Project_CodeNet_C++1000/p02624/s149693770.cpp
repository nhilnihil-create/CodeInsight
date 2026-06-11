#include <iostream>
using namespace std;

int main(){
    int n;
    long long ans = 0;
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j+=i ){
            ans += j;
        }
    }
    cout << ans << endl;

}
