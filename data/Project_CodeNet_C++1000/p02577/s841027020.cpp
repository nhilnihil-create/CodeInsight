#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    string s;
    cin >> s;
    int d = 0;
    for(int i=0;i<s.size();i++){
        d += (int)(s[i]-'0');
        d %= 9;
    }
    if(d==0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}