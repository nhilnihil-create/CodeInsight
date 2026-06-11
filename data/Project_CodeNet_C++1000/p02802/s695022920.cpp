#include <bits/stdc++.h>
#include <queue>

using namespace std;


int main() {
    int n,m; cin >> n >> m;
    vector<int> p(m);
    vector<string> s(m);
    vector<int> a(n,0);
    vector<bool> b(n,false);

    long ac = 0;
    long wa = 0;
    for(int i=0; i<m; i++){
        cin >> p[i] >> s[i];
        p[i]--;
        if(!b[p[i]]){
            if(s[i] == "AC"){
                b[p[i]] = true;
            }else{
                a[p[i]]++;
            }
        }
    }
    for(int i=0; i<n; i++){
        if(b[i]){
            ac++;
            wa += a[i];
        }
    }
    // long ac = 0;
    // long wa = 0;
    // for(int i=0; i<m; i++){
    //     cin >> p[i] >> s[i];
    //     p[i]--;

    //     if(s[i] == "AC" && a[p[i]] == 0){
    //         a[p[i]]++;
    //         ac++;
    //     }
    //     if(s[i] == "WA" && a[p[i]] == 0){
    //         wa++;
    //     }
    // }
    cout << ac << " " << wa << endl;



}