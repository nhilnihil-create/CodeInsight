#include <bits/stdc++.h>
using namespace std;
int main(){
        int n; cin >> n;
        string s; cin >> s;
        string abc = "ABC";
        int cnt = 0;
        for (int x = 0; x <= n-3; ++x){
            string c = s.substr(x, 3);
            //cout << c << endl;
            if (c == abc) cnt++;
        }
        cout << cnt << endl;
    return 0;
}

