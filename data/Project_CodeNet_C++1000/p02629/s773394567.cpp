#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n;
    cin >> n;
    string ans="";
    while(n>0){
        n-=1;
        ans = (char)('a'+(n%26))+ans;
        n/=26;
    }
    cout << ans;
    return 0;
}