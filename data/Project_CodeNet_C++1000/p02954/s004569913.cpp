#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


void RL(int r,int l){
    rep(i,r-1) cout << 0 << " ";
    cout << r/2+r%2 + l/2<< " " << r/2 + l/2 + l%2 << " ";
    rep(i,l-1) cout << 0 << " ";
    
}

int main(){
    
    string s;
    cin >> s;
    int n = s.size();

    vector<int> v;
    v.assign(n,0);

    int cntr = 1;
    int cntl = 0;
    char temp = 'R';
    for(int i = 1;i < n-1;i++){
        if(temp == s[i]){
            if(temp == 'R') {
                cntr++;
            }
            else {
                cntl++;
            }
        }else{
            if(temp == 'L'){
                // cout << cntr << " " << cntl<< endl;
                RL(cntr,cntl);
                cntl = 0;
                cntr = 1;
                temp = 'R';
            }else{
                cntl++;
                temp = 'L';
            }
        }
    }

    if(temp == 'R') RL(cntr,1);
    else RL(cntr,cntl+1);
    cout << endl;
}