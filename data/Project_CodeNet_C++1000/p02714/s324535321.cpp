#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; string s;
    cin >> n >> s;

    vector<long long int> color(3);
    for(int i=0; i<n; i++){
        if(s[i] == 'R') color[0] += 1;
        if(s[i] == 'G') color[1] += 1;
        if(s[i] == 'B') color[2] += 1;
    }

    long long int ans = color[0] * color[1] * color[2];
    for(int d=1; d<=n/2; d++){
        for(int i=0; i+2*d<n; i++){
            if(s[i]   != s[i+d]
            && s[i]   != s[i+2*d]
            && s[i+d] != s[i+2*d]) ans -= 1;
        }
    }
    cout << ans << endl;
    return 0;
}