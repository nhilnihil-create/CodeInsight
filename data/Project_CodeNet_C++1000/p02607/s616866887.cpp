#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    
    int res = 0;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if(x%2 && i%2){
            res += 1;
        }
    }
    
    cout << res << endl;
    
}
