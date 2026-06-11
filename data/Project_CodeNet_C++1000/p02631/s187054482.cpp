// Red Scarf 
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){cin >> a[i];}
    int ans;
    int sum=a[0];
    for(int i=1; i<n; i++){sum^=a[i];}
    for(int i=0; i<n; i++){
        int ans=a[i]^sum;
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}