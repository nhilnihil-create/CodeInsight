#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, result=0; bool flag=false; cin >> n;
    for(int i=1;i<=n;i++){
        if(n == floor(i*1.08)) {flag = true; result = i; break;}
    }
    if(flag == true) cout << result << endl;
    else cout << ":(" << endl;
    return 0;
}

