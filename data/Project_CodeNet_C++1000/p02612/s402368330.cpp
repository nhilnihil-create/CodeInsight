#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin >> N;
    
    int a = N%1000;
    int ans=0;
    if(a!=0) {
        ans=1000-a;
    }
    
    cout << ans << endl;
}