#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array


int x , y ;

void solve(){

    cin >> x >> y;

    bool ans = false;


    int tmp;
    while(x > 0){
        if(y % 4 == 0 && y/4 == x || y % 2 == 0 && y/2 == x){
            ans = true;
            break;
        }

        x--;
        y = y-2;
    }

    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;

}





int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

}