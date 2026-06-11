#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    /*s.size() aaaaa は　５、 bbbb は４
    　奇数のとき　0-4, 1-3　で 5/2 - 1
    　偶数のとき　0-3, 1-2  で 4/2 
    */
    int m = s.size();
    int cnt = 0;

    if(m % 2 == 0) {
        for(int i=0; i< m/2; i++){
            if(s[i] != s[m-i-1]) cnt++;
        }
    }
    else {
        for(int i=0; i< m/2 ; i++) {
            if(s[i] != s[m-i-1]) cnt++;
        }
    }

    cout << cnt << endl;
}