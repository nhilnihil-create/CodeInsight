#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >>n;
    string s; cin >>s;
    int w = 0;
    for(int i = 0; s[i]; i++){
        w += (s[i] == 'W');
    }

    int ans = 0;
    int p = s.length()-1;
    for(int i = 0; i<w; i++, p--){
        if(s[p] == 'R') ans++;
    }

    cout <<ans <<endl;

    return 0;
}
