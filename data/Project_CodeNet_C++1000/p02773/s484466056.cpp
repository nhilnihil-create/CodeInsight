#define _GLIBCXX_DEBUG
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
using vs = vector<string>;

int main(void){
    int n;
    cin >> n;
    vs key;
    map<string, int> cnt;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        if(cnt.count(s)) cnt.at(s)++;
        else {cnt[s] = 1; key.push_back(s);}
    }
    sort(key.begin(), key.end());
    int mx=0;
    for(string &s : key) if(cnt.at(s)>mx) mx = cnt.at(s);
    for(string &s : key) if(cnt.at(s)==mx) cout << s << '\n';
    return 0;
}