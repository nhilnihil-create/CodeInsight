#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    string s;
    cin >> s;
    
    string ans = "Yes";
    int max_ = 0, count = 0;
    if(c>d){
        for(int i = b-2; i <= d; i++){
            if(s.at(i) == '.') count++;
            else count = 0;
            max_ = max(max_, count);
        }
        if(max_<3) ans = "No";
    }
    count = 0;
    for(int i = a-1; i < c; i++){
        if(s.at(i) == '#') count++;
        else count = 0;
        if(count>=2) ans = "No";
    }
    count = 0;
    for(int i = b-1; i < d; i++){
        if(s.at(i) == '#') count++;
        else count = 0;
        if(count>=2) ans = "No";
    }
    
    cout << ans << endl;
    return 0;
}