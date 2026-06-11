#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int N; cin >> N;
    string S; cin >> S;
    vector<set<int>> x(10);
    for(int i = 0; i < N; i++){
        int d = S[i] - '0';
        x[d].insert(i);
    }
    int ans = 0;
    for(int a = 0; a <= 9; a++){
        for(int b = 0; b <= 9; b++){
            for(int c = 0; c <= 9; c++){
                int pos = -1;
                if(x[a].upper_bound(pos) == x[a].end())continue;
                pos = *x[a].upper_bound(pos);
                if(x[b].upper_bound(pos) == x[b].end())continue;
                pos = *x[b].upper_bound(pos);                
                if(x[c].upper_bound(pos) == x[c].end())continue;
                pos = *x[c].upper_bound(pos);
                ans++;
            }
        }
    }
    cout << ans << endl;
}
