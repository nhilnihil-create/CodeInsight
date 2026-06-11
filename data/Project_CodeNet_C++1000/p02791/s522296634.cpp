#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,ans=0,min;
    cin >>n;
    int p[n];
    for(int i=0;i<n;i++) cin >> p[i];
    min=p[0]; ans++;
    for(int i=1;i<n;i++){
        if(min>p[i]){
            ans++;
            min=p[i];
        }
    }
    cout << ans;
}