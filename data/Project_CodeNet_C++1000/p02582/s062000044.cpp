#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    string s;
    cin >> s;
    int ans = 4;
    if(s=="RRS" || s=="SRR") ans = 2;
    else if(s=="RSS"||s=="SRS"||s=="SSR"||s=="RSR") ans = 1;
    else if(s=="SSS") ans = 0;
    else ans = 3;
    cout << ans << endl;
    return 0;
}