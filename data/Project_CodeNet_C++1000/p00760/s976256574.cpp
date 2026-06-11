#include <bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = n - 1; i >= 0; i--)
#define REP(i,k,n) for(int i = k; i < n; i++)

#define vi vector<int>
#define pb push_back
using namespace std;

typedef long long ll;

int main(){

    int n;
    cin >> n;
    rep(i,n){
        int y,m,d;
        cin >> y >> m >> d;
        //誕生年は含まないで計算
        int by = 999 / 3 - y / 3;
        int sy = (999 - y) - by;
        ll sday = by * 20 * 10 + sy * (20 * 5 + 19 * 5);
        if(y % 3 == 0) {
            sday += (20 - d + 1) + (10 - m) * 20;
        }else{
            if(m % 2 == 1) {
                sday += (20 - d + 1) + (10 - m) / 2 * 20 + ((10 - m) / 2 + 1) * 19;
            }else{
                sday += (19 - d + 1) + (10 - m) / 2 * 19 + (10 - m) / 2 * 20;
            }
        }
        cout << sday << endl;
    }

    return 0;

}

