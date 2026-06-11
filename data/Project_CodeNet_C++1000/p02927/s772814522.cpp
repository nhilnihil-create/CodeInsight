#include <bits/stdc++.h>

using namespace std;
#define int long long
int MOD = 1000000007;


signed main(){
    int M,D;
    cin >> M >> D;
    
    int one=0,ten=0,cnt=0;
    for(int k=0;k<=M;k++){
        for(int i=22;i<=D;i++){
            one = i%10;
            ten = i/10;
            if(k==ten*one && one>1) cnt++;
        }
    }
    
    cout << cnt << endl;
    return 0;
}
