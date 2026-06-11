#define _GLIBCXX_DEBUG
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(void){
    int n;
    cin >> n;
    map<string, int> cnt;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        cnt[s]++;
    }
    int mx=0;
    for(const auto &x : cnt) if(x.second > mx) mx = x.second;
    for(auto itr=cnt.begin(); itr!=cnt.end(); itr++)
        if(itr->second == mx) cout << itr->first << '\n';
    return 0;
}