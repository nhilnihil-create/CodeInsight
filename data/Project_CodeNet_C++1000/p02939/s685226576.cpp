#include <bits/stdc++.h>
using namespace std;
constexpr long long MOD = 1000000007;
using ll = long long;
int main() {
string s;
cin >> s;
ll n = s.size();
ll ans = 0;
bool isone = false;
ll index = 0;
while(index<n){
    if(index==n-2&&s[index]==s[index+1LL]){
        ans++;
        break;
    }
    if(isone&&s[index-1]==s[index]){
        ans++;
        index += 2;
        isone = false;
    }
    else{
        ans++;
        index++;
        isone = true;
    }
}
cout << ans << endl;
}
