#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define pi acos(-1.0)

int main()
{
    ll i, j, n, m, k = 65;
    string s;
    cin >> n >> s;
    vector < pair < char, int > > vp(26);
    for(i = 0; i < 26; i++){
        vp[i].first = char(k++);
        vp[i].second = i;
    }
//
//    for(auto it : vp){
//        cout << it.first << " " << it.second << endl;
//        cout << vp[(it.second + n) % 26].first << endl;
//    }

    for(i = 0; i < s.size(); i++){
        cout << vp[(vp[s[i] - 65].second + n) % 26].first;
    }

    cout << endl;

    return 0;
}
