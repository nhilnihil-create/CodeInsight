#include <bits/stdc++.h>

using namespace std;
using ll = long long;
string s;
ll sum;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>s;
    for(char c : s) sum += c-'0';
    cout<<(sum % 9 ? "No" : "Yes");
}
