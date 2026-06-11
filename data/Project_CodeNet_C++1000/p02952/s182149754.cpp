#include <iostream>
#define rep(i, n)for(int i=0; i<n; i++)
using namespace std;

int main(){
    int n, ans=0;
    cin >> n;
    for(int i=1; i<=n; i++){
        int digit = 0;
        int x = i;
        while(x){
            digit++;
            x /= 10;
        }
        if(digit%2 != 0)ans++;
    }
    
    cout << ans << endl;
    
    return 0;
}
