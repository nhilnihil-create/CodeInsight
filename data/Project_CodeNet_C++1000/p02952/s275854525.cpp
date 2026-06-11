#include <iostream>
#define rep(i, n)for(int i=0; i<n; i++)
using namespace std;

bool f(int x){
    int digit =0;
    while(x){
        digit++;
        x /= 10;
    }
    return digit%2 != 0;
}

int main(){
    int n, ans=0;
    cin >> n;
    for(int i=1; i<=n; i++){
       if(f(i)) ans++;
    }
    
    cout << ans << endl;
    
    return 0;
}
