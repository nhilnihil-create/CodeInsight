#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >>s;
    long long ret = 0;
    vector<long long> v(s.size()+1);
    for (int i = 0; i <= s.size(); i++) {v[i]=0;}
    for (int i = 0; i <= s.size(); i++) {if(s[i]=='<'){v[i+1]=max(v[i+1],v[i]+1);}}
    for (int i = s.size(); i >= 0; i--) {if(s[i]=='>'){v[i]=max(v[i],v[i+1]+1);}}
    for (int i = 0; i <= s.size(); i++) ret += v[i];
    cout << ret << endl;
    return 0;
}