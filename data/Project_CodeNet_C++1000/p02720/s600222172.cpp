#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)



int main() {
    int k;
    cin >> k;
    
    queue<long int> q;
    for(int i = 1; i <= 9; i++) {
        q.push(i);
    }
    
    while(k > 1) {
        for(int i = -1; i <= 1; i++) {
            long int o = q.front() % 10 + i;
            if(o >= 0 && o <= 9) {
                q.push(q.front()*10 + o);
            }
            if(k == 0)
                break;
        }
        q.pop();
        k--;
    }
        
    cout << q.front() << endl;

    
    return 0;
}
