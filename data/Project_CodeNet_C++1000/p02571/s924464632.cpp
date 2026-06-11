#include <bits/stdc++.h>
using namespace std;
int const MX = 2e5 + 2;

int main()
{
    string s, t;
    cin>>s>>t;
    int mi = MX;
    for(int i = 0; i < s.size() - t.size() + 1; i++){
        int cnt = 0;
        for(int j = 0; j < t.size(); j++){
            if(s[i + j] != t[j]) cnt++;
        }
        mi = min(mi, cnt);
    }
    cout<<mi;
}


