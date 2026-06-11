#include <bits/stdc++.h>
using namespace std;;

int main(){
    int n,x,t;
    cin >> n >> x >> t;
    int count = n/x;
    int ans;
    if (n%x != 0){
        ans = (count+1)*t;
    }else{
        ans = count*t;
    }
    cout << ans << endl;
}