#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int w[100];
    cin >> n;
    int sum=0;
    for(int i=0;i<n;i++){
        cin >> w[i];
        sum += w[i];
    }
    int ans=1000000;
    int now=0;
    for(int i=0;i<n;i++){
        now += w[i];
        if(abs(sum-2*now)<=ans){
            ans = abs(sum-2*now);
        }
    }
    cout << ans;
    return 0;
}