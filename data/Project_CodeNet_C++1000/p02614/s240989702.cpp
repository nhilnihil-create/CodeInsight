#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, w, k;
    cin >> h >> w >> k;

    vector<string> s(h);
    for(int i=0; i<h; i++){
        cin >> s[i];
    }

    int ans = 0;
    for(int bit=0; bit<(1<<(h+w)); bit++){
        int count = 0;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if((bit >> i & 1) 
                && (bit >> (h+j) & 1)
                && s[i][j] == '#'){
                    count += 1;
                }
            }
        }
        if(count == k) ans += 1;
    }
    cout << ans << endl;
    return 0;
}