#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(),a.end());

    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(a[i]==a[j]||a[j]==a[k]) continue;
                if(a[i]+a[j]>a[k]) ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}