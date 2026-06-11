#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        if(x % 2 == 0){
            if(x % 3 == 0) continue;
            if(x % 5 == 0) continue;
            return cout << "DENIED", 0;
         }
    }
    cout << "APPROVED";
    

    return 0;
}
