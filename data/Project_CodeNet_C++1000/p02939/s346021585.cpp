#include <bits/stdc++.h>
using namespace std;

int main(){

    string s;
    cin >> s;

    int num = s.size();
    int ans = 0;
    char cbuf, cmem;

    for (int i=0; i<num; i++){

        cbuf = s.at(i);

        if (cbuf == cmem){
            if (i+1<num){
                ans++;
                cmem = ' ';
                i++;
            }
        }
        else {
            cmem = cbuf;
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}