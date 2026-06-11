#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for(int i = 0; i < 1000; i++){
        int p, q, r;
        p = i % 10;
        r = i / 100;
        q = (i % 100) / 10;
        bool a, b;
        int id1, id2;
        id1 = -1;
        a = false;
        b = false;
        for(int j = 0; j < n; j++){
            if(!a && s.at(j) - '0' == r && id1 == -1){
                a = true;
                id1 = j;
                continue;
            }
            if(!b && a && s.at(j) - '0' == q && id1 != j){
                b = true;
                id2 = j;
                continue;
            }
            if(b && s.at(j) - '0' == p && id2 != j){
                ans ++;
                //cout << i << endl;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}