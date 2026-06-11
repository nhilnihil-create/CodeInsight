#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> cnt(n, 0);
    vector<bool> wc(n, false);
    int i, ac = 0, pen = 0;
    for(i=0; i<m; i++){
        int x;
        string s;
        cin >> x >> s;
        x--;
        if(!wc[x]){
            if(s=="AC"){
                ac++;
                pen += cnt[x];
                wc[x] = true;
            }
            else cnt[x]++;
        }
    }
    cout << ac << " " << pen << endl;
    return 0;
}