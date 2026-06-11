#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    string s; cin >> s;
    vector<int> c(s.size(), 0);
    int i = 0;
    while(i<s.size()){
        int r = 0, l = 0;
        int rp, lp;
        while(s[i]=='R'){r++; i++;}
        if(s[i]=='L'){lp = i; rp = lp-1;}
        while(s[i]=='L'){l++; i++;}
        c[rp] += (r+1)/2;
        c[lp] += r/2;
        c[lp] += (l+1)/2;
        c[rp] += l/2;
    }
    for(int i=0; i<s.size(); ++i){cout << c[i] << endl;}
    return 0;
}