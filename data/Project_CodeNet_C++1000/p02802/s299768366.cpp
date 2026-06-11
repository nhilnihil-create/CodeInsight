#include <bits/stdc++.h>
using namespace std;


int main() {
    int n,m;
    cin >> n >> m;
    vector<bool>ac(n + 1,false);
    vector<int>wa(n + 1,0);
    int pc = 0,sc = 0;
    for(int i = 0;i < m;i++){
        int p;
        string s;
        cin >> p >> s;
        if(!ac[p]){
            if(s == "AC"){
                ac[p] = true;
                sc += wa[p];
                pc++;
            }else{
                wa[p]++;
            }
        }
    }
    cout << pc << " " << sc;
}