#include <bits/stdc++.h>
using namespace std;

int main(){
    string s, t;
    cin >> s >> t;

    vector<vector<int>> alphabet(26);
    for(int i=0; i<s.length(); i++){
        alphabet[s[i] - 'a'].push_back(i);
    }

    long long int ans = 0;
    int current = 0;
    for(int i=0; i<t.length(); i++){
        //cout << i << " : s[" << current << "] = " << s.substr(current) << endl;
        if(alphabet[t[i] - 'a'].size() == 0){
            cout << -1 << endl;
            return 0;
        }

        auto pos = lower_bound(alphabet[t[i] - 'a'].begin(), alphabet[t[i] - 'a'].end(), current);
        if(pos == alphabet[t[i] - 'a'].end()){
            ans += s.length();
            current = 0;
        }
        
        //cout << *lower_bound(alphabet[t[i] - 'a'].begin(), alphabet[t[i] - 'a'].end(), current) << endl;
        if(i == t.length() - 1){
            ans += *lower_bound(alphabet[t[i] - 'a'].begin(), alphabet[t[i] - 'a'].end(), current) + 1;
        }
        current = *lower_bound(alphabet[t[i] - 'a'].begin(), alphabet[t[i] - 'a'].end(), current) + 1;
        //cout << ans << ", " << current << endl;
    }
    cout << ans << endl;
    return 0;
}