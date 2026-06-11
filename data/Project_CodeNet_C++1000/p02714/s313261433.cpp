#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using P = pair<int, int>;

#define roop(i, n) for(int i = 0;i < n;i++)

int main(void){

    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<vector<int>> a(n, vector<int>(3));
    int r = 0, g = 0, b = 0;
    roop(i, n){
        if(s[i] == 'R') r++;
        else if(s[i] == 'G') g++;
        else b++;

        a[i][0] = r;
        a[i][1] = g;
        a[i][2] = b;
    }

    ll ans = 0;

    int temp = 0;
    for(int i = 0;i < n-2;i++){
        for(int j = i+1;j < n-1;j++){
            if(s[i] != s[j]){
                if(s[i] == 'R' || s[j] == 'R') temp += 1;
                if(s[i] == 'G' || s[j] == 'G') temp += 2;
                if(s[i] == 'B' || s[j] == 'B') temp += 4;

                if(j+(j-i) < n){
                    if(7 - temp == 1 && s[j+(j-i)] == 'R') ans--;
                    if(7 - temp == 2 && s[j+(j-i)] == 'G') ans--;
                    if(7 - temp == 4 && s[j+(j-i)] == 'B') ans--;
                }

                if(7 - temp == 1) ans += a[n-1][0]-a[j][0];
                if(7 - temp == 2) ans += a[n-1][1]-a[j][1];
                if(7 - temp == 4) ans += a[n-1][2]-a[j][2];
            }
            temp = 0;
        }
    }

    cout << ans << endl;

    return 0;
}
