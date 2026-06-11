#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    if(s=="RRR") cout << "3" << "\n";
    else if(s=="RRS"||s=="SRR") cout << "2" << "\n";
    else if(s=="SSS") cout << "0" << "\n";
    else cout << "1" << "\n";
    return 0;
}