#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,k=0,ans=0;
    cin >> n;
    string a[n];
    int b[n];
    for(int i=0;i<n;i++){
        cin >> a[i] >> b[i];
    }
    string x;
    cin >> x;
    for(int i=0;i<n;i++){
        if(a[i]==x) k = i;
    } 
    for(int i=k+1;i<n;i++) ans += b[i];
    cout << ans << endl;
}
