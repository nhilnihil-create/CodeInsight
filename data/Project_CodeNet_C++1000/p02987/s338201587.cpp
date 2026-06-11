#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main(){
    Hello
    string s;
    cin >> s;
    map<char, int> mp;
    for(int i = 0; i < s.size(); i++)
        mp[s[i]]++;
    if(mp.size() != 2)
        cout << "No";
    else {
        bool ok = true;
        for(auto i : mp)
            if(i.second != 2)
                ok = false;
        if(ok)
            cout << "Yes";
        else
            cout << "No";
    }
    return 0;
}
