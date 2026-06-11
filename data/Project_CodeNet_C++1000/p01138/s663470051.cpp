#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int pop[24*3600+5];

inline int ss(char c) { return c-'0'; }

int stoi(string s) {
    return (ss(s[0])*10+ss(s[1]))*3600 + (ss(s[3])*10 + ss(s[4]))*60
        + ss(s[6])*10 + ss(s[7]);
}

int main() {
    int n;
    string s,t;
    while(cin>>n, n) {
        memset(pop, 0, sizeof(pop));
        for(int i=0; i<n; ++i) {
            cin>>s>>t;
            int ts = stoi(s), tt = stoi(t);
            for(int i=ts; i<tt; ++i) pop[i]++;
        }

        int ans = 0;
        for(int i=0; i<=24*3600; ++i) ans = max(ans, pop[i]);
        cout<<ans<<endl;
    }
}