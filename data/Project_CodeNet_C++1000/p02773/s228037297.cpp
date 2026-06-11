#include <iostream>
#include <map>
#include <iterator>
#include <string>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    map<string, int> si;

    for (int i = 0; i < n; i++) {
        string s; cin>>s;
        si[s]++;
    }

    int m = -1e9;
    for (auto it = si.begin(); it != si.end(); it++) 
        m = max(m, it->second);
    for (auto it = si.begin(); it != si.end(); it++) {
        if (it->second == m) cout<<it->first<<endl;
    }

    return 0; 
}
