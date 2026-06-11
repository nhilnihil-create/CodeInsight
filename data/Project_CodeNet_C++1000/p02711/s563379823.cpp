#include <bits/stdc++.h>
using  namespace  std;

int main() {

    int n;
    cin>>n;

    bool flag = false;
    while(n){
        int rem = n%10;
        if(rem==7){
            flag = true;
            break;
        }
        n = n/10;
    }

    if(flag){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
}
