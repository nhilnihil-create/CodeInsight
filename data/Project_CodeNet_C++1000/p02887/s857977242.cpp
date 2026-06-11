#include <iostream>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    for (int i = 0; i < n-1; i++)
    {
        if(s[i] == s[i+1]) continue;
        ans++;
    }
    cout << ans+1 << endl;
    return 0;
}