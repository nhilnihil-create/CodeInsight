#include <bits/stdc++.h>
using namespace std;  

int main(){
    int n, d, num[100001] = {}, ans;
    cin >> n; 
    
    for ( int i = 0; i < n; i++ ) {
        cin >> d;
        num[d]++;
    } 
    
    for ( int i = 0; i < 100000; i++ ) {
        num[i+1] += num[i];
    }
    
    ans = 0;
    for ( int i = 1; i < 100000; i++ ) {
        if ( num[100000] - num[i] == num[i] ) {
            ans ++;
        }
    } 
    
    cout << ans << endl;
    
    return (0);
}