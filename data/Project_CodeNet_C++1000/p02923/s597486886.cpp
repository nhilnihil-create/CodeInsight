#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int h[100010];
    for(int i=0; i<n; i++){
        cin >> h[i];
    }
    int count=0;
    int ans=0;

    for(int i=0; i<n-1; i++){
        if(h[i]>=h[i+1]){
            count++;
            ans=max(count,ans);
        }
        else count=0;
    }
    cout << ans << endl;
}