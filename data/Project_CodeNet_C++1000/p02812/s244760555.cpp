#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    int st = 0;
    while(st != -1){
        st = s.find("ABC");
        st++;
        if(st == 0) break;
        cnt++;
        s.erase(s.begin(), s.begin() + st);
    }
    cout << cnt;

    return 0;
}
