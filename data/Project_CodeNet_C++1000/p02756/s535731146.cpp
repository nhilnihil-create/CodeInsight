#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int q;
    cin >> s >> q;
    deque<char> chars{s[0]};
    for(int i=1; i < (int)s.length(); i++){
        chars.push_back(s[i]);
    }
    int rev = 0;
    for (int i = 0; i < q; i++)
    {
        int t;
        cin >> t;
        if(t == 1)rev++;
        else if(t == 2){
            int f;
            char c;
            cin >> f >> c;
            if(rev%2 == 0 && f == 1)chars.push_front(c);
            else if(rev%2 == 0 && f == 2)chars.push_back(c);
            else if(rev%2 == 1 && f == 1)chars.push_back(c);
            else chars.push_front(c);
        }
    }
    string ans = "";
    if(rev%2 == 0){
        for(auto c :chars)ans += c;
        // for(auto itr = chars.begin(); itr != chars.end(); ++itr){
        //     ans += *itr;
        // }
        // ans += *chars.end(); 
    }
    else if(rev%2 == 1){
        reverse(chars.begin(), chars.end());
        for(auto c :chars)ans += c;
        // for(auto itr = chars.end(); itr != chars.begin(); --itr){
        //     ans += *itr;
        // }
        // ans += *chars.begin(); 
    }
    cout << ans << endl;
    
    return 0;
}