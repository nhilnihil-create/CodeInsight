#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); i++)
using namespace std;
using ll = long long;
typedef pair<string,int> P;

int main(void) {
    int N; cin >> N;
    vector<string> S;
    map<string,int> mp;
    for(int i=0; i<N; i++) {
        string s; cin >> s;
        S.push_back(s);
        mp[s] = 0;
    }

    for(int i=0; i<N; i++) mp[S[i]]++;

    int max_value = 0;
    for(auto itr = mp.begin(); itr != mp.end(); ++itr)  if(max_value<itr->second) max_value = itr->second;
    
    //cout << endl;
    for(auto itr = mp.begin(); itr != mp.end(); ++itr) {
        if(itr->second==max_value) cout << itr->first << endl;
    }
}