#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<string> s(100000);
    map<string, int> mp;
    long long ans =0;
    for(int i=0; i<n; i++){
        cin >> s[i];
        sort(s[i].begin(), s[i].end());
        if(mp.count(s[i])){
            ans += mp[s[i]];
            mp[s[i]]++;
        }else{
            mp[s[i]] = 1;
        }
    }
    cout << ans << endl;
    return 0;

}