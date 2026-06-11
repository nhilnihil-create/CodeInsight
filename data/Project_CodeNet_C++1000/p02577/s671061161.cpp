#include <bits/stdc++.h>
using namespace std;
int main(void){
    string n;
    long ans =0;
    cin >> n;
    for(int i=0;i<n.size();i++){
        ans += n[i]-'0';
    }
    if(ans%9==0) cout << "Yes" << endl;
    else cout << "No" << endl;
}