#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<int> p(m);
    vector<string> s(m);
    for(int i=0; i<m; i++) cin >> p[i] >> s[i];

    int ac=0, pena=0;
    vector<int> wa(n);
    vector<bool> flg(n);
    for(int i=0; i<n; i++){
        flg[i] = false; wa[i]=0;
    }

    for(int i=0; i<m; i++){
        if(s[i]=="AC" && !flg[p[i]-1]){
            flg[p[i]-1] = true; ac++;
            pena += wa[p[i]-1];
        }
        if(s[i]=="WA" && !flg[p[i]-1]){
            wa[p[i]-1]++;
        }
    }
    printf("%d %d\n", ac, pena);
    return 0;
}