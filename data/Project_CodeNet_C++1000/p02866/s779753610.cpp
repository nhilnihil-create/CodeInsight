#include <bits/stdc++.h>
using namespace std;

long long d[100000];
int main() {
    long long n;
    cin >> n;
    long long a;
    long long ans=1;
    for(int i=0;i<n;i++){
        cin >> a;
        d[a]++;
        if(i==0&&a>0){
            ans=0;
            cout << ans << endl;
            return 0;
        }
        else if(i!=0&&a==0){
            ans=0;
            cout << ans << endl;
            return 0;
        }
    }
    long long m;
    for(int i=0;i<n-1;i++){
        if(d[i]>0) m=i;
        if(d[i]==0&&d[i+1]!=0){
            ans=0;
            cout << ans << endl;
            return 0;
        }
    }
    long long mod=998244353;
    for(int i=1;i<m;i++){
        for(int j=0;j<d[i+1];j++){
            ans=ans*d[i]%mod;
        }
    }
    cout << ans << endl;
    return 0;
}