#include<bits/stdc++.h>
using namespace std;

int c[1000005];
int main(){
    int n;
    cin >> n;
    int a[n+1];
    for(int i=0;i<n;i++)cin >> a[i];
    sort(a,a+n);
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=a[i];j<=a[n-1];j+=a[i])c[j]++;
    }
    for(int i=0;i<n;i++)if(c[a[i]]==1)ans++;
    cout << ans << endl;
}
