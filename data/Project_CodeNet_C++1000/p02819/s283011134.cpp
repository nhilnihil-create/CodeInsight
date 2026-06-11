#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    int x;
    cin >> x;
    
    int ans = -1;
    vector<int> prime;
    prime.push_back(2);
    
    if(x == 2)
        ans = 2;
    else {
        for(int i = 3; i < 1000000; i+=2) {
            bool tf = true;
            rep(j,prime.size()) {
                if(i % prime[j] == 0) {
                    tf = false;
                    break;
                }
            }
            if(tf) {
                prime.push_back(i);
                if(i >= x) {
                    ans = i;
                    break;
                }
            }
        }
    }
    
    cout << ans << endl;
    
    
    
    return 0;
}


