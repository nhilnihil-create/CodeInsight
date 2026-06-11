#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
int32_t main(){
    
    int n;
    cin >> n;
    for(int i=1;i <= 9;i++){
        if(n%i == 0 && n/i >= 1 && n/i <= 9){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No\n";
}

