#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    int n;
    string s;
    cin >> n >> s;
    
    int cnt = 0;
    for(int i = 0; i < n-2; i++) {
        if(s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C')
            cnt++;
    }
    
    cout << cnt << endl;
    
    
    
    return 0;
}
