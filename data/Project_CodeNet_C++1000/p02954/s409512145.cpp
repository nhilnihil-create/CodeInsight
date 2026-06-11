#include <bits/stdc++.h>
using namespace std;
int main(void){
    string s;
    cin >> s ;
    
    vector<int> c(s.size());
    int oddcnt = 0, evencnt = 0, rp, lp, rcnt = 0, lcnt;
    for(int i = 0; i < s.size(); i++){
        if(s.at(i) == 'R'){
            if(rcnt % 2 != 0){
                oddcnt++;
            } else {
                evencnt++;
            }
            rcnt++;
        } else if (s.at(i) == 'L') {
            if(evencnt != 0){
                if(rcnt % 2 == 0){
                    c.at(i - 1) = oddcnt;
                    c.at(i) = evencnt + 1;
                } else {
                    c.at(i - 1) = evencnt;
                    c.at(i) = oddcnt + 1;
                }
                rcnt = 0;
                evencnt = 0;
                oddcnt = 0;
                rp = i - 1;
                lp = i;
                lcnt = 0;
            } else {
                if(lcnt % 2 != 0){
                    c.at(lp)++;
                } else {
                    c.at(rp)++;
                }
                lcnt++;
            }
        }
        //printf("%d %d\n", evencnt, oddcnt);
    }
    
    for(int i = 0; i < s.size(); i++){
        cout << c.at(i) ;
        if(i == s.size() - 1){
            cout << endl;
        } else {
            cout << " " ;
        }
    }
    
}
