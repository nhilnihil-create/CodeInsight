#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
#define forn(b) for(int i = 0; i < b; i++)
#define rforn(b) for(int i = b - 1 ;i >= 0; i--)
#define It(m) for(auto it = m.begin(); it != m.end(); it++)
#define N 500500
#define PI 3.14159265358979323846264338327950L
#define speed ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
const ll mod = (ll)1e9 + 7;
    
int main(){
    speed;
    string s, t; cin >> s >> t;
    vector<int> v1(27);
    vector<int> v2(27);
    for(int i = 0; i < s.size(); i++) {
        v1[s[i] - 'a']++;
    }   
    for(int i = 0; i < t.size(); i++) {
        v2[t[i] - 'a']++;
    }
    bool yes = true;
    for(int i = 0; i < 27; i++) {
        if(v2[i] != 0 && v1[i] == 0) {
            yes = false;
            break;
        }
    }
    if(yes) {
        vector<vector<int>> loc(27);
        vector<int> data(27);
        for(int i = 0; i < 27; i++) {
            vector<int> a(v1[i]);
            loc[i] = a;
        }
        for(int i = 0; i < s.size(); i++) {
            int j = data[s[i] - 'a'];
            data[s[i] - 'a'] = j + 1;
            loc[s[i] - 'a'][j] = i;
        }
        long long answer = 0;
        int n = s.size();
        int current = 0;
        for(int i = 0; i < t.size(); i++) {
            auto k = lower_bound(loc[t[i] - 'a'].begin(), loc[t[i] - 'a'].end(), current) - loc[t[i] - 'a'].begin();
            if(k == loc[t[i] - 'a'].size()) {
                answer += n;
                current = 0;
                i--;
            }
            else {
                current = loc[t[i] - 'a'][k] + 1;
            }
        }
        answer += current;
        cout << answer;
    }
    else {
        cout << -1;
    }
    return 0;
}