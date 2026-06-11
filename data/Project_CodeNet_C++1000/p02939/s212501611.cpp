#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    int cnt = 0;
    int i = 1;
    bool single = true;
    s += '?';

    while(i <= n){
        if(single && s[i] == s[i-1]) {
            i++;
            single = false;
            cnt++;
        }
        else single = true, cnt++;
        i++;
    }

    cout << cnt << endl;

    return 0;
}