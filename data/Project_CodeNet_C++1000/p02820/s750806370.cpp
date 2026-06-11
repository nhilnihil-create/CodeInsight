#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k, r, s, p; string t;
    cin >> n >> k >> r >> s >> p >> t;
    vector<int> f(t.size(), 0);
    for(int i=0; i+k<t.size(); ++i){
        if(t[i]==t[i+k]){t[i+k] = 1-t[i];}
    }
    int res = 0; 
    for(int i=0; i<t.size(); ++i){
        
        if(t[i]=='r'){
            if(f[i]==1){continue;}
            else{res += p;}
        }
        else if(t[i]=='s'){
            if(f[i]==1){continue;}
            else{res += r;}
        }
        else if(t[i]=='p'){
            if(f[i]==1){continue;}
            else{res += s;}
        }
    }
    cout << res << endl;
    return 0;
}