#include<iostream>
using namespace std;

int main(){
    int n,x,t,ans;
    cin >> n >> x >> t;
    if(n%x == 0){
        ans = (n/x)*t;
    }
    else{
        ans = (n/x + 1)*t;
    }
    cout << ans << endl;
    return 0;
}