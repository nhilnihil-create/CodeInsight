#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
bool prime(int n){
    bool flag = true;
    for(int i=2; i*i<=n; i++){
        if(n%i==0){
            return false;
        }
    }
    return flag;
}
int main(){
    IOS;
    int n;
    cin >> n;
    for(int i=n; i<n+100; i++){
        if(prime(i)==true){
            cout << i <<endl;
            break;
        }
    }
}