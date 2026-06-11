#include<bits/stdc++.h>
using namespace std;

int main(){
    int A, B, ans = 0;
    cin >> A >> B;
    while(A * ans - (ans - 1) < B) ++ans;
    cout << ans << endl;
    return 0;
}