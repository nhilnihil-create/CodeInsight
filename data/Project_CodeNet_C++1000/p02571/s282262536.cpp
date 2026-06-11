#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define maxi 9999999
void go();



int main() {
    //freopen("input.txt","r",stdin);
    go();
    string s,t;
    cin >> s >> t;
    //cout << s << endl;
    //cout << t << endl;
    int i,j,ans=100000;
    for(i=0; i<=s.size()-t.size(); i++) {
        int dif=0;
        for(j=0; j<t.size(); j++) {
            if(t[j]!=s[j+i]) dif++;
        }
        ans=min(ans,dif);
    }
    cout << ans << endl;
}



void go() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}