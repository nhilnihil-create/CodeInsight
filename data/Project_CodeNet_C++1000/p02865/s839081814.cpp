#include <bits/stdc++.h>

using namespace std;
#define int long long


signed main(){
    int N;
    cin >> N;
    
    int cnt = 0;
    for(int i=1;i<N;i++){
        int k = N-i;
        if(k != 0 && i != k) cnt++;
    }
    
    cout << cnt/2 << endl;
    
    return 0;
}
