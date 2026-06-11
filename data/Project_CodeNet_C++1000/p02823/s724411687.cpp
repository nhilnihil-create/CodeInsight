#include <iostream>
using namespace std;
int main(){
    long long n, a, b, ans;
    cin >> n >> a >> b;
    if(a%2==1&&b%2==1){
        ans = (b-a) / 2;
        cout << ans << endl;
    }else if(a%2==0&&b%2==0){
        ans = (b-a) / 2;
        cout << ans << endl;
    }else{
        ans = min(n-b,a-1) + 1 + (b - a -1) / 2;
        cout << ans << endl;
    }
    return 0;
}
