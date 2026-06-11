#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<string> s(n);
    map<string, int> d; 
    for(int i=0; i<n; ++i){cin >> s[i]; d[s[i]]++;}
    int cnt = 0;
    for(auto i=d.begin(); i!=d.end(); ++i){
        cnt = max((i->second), cnt);
    }
    for(auto i=d.begin(); i!=d.end(); ++i){
        if((i->second!=cnt)){continue;}
        cout << i->first << endl;
    }
    return 0;
}