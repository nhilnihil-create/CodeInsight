#include<bits/stdc++.h>
#include<string>
using namespace std;
#define rep(i,n) for(long long int i=0;i<(long long int)(n);i++)

int main(){
    int n,k;
    cin >> n >> k;
    
    int d[k];
    int a[k][n];
    bool have_o[n+1];
    
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            a[i][j] = 0;
        }
    }
    for(int i=0;i<=n;i++){
        have_o[i] = false;
    }
    
    for(int i=0;i<k;i++){
        cin >> d[i];
        for(int j=0;j<d[i];j++){
            cin >> a[i][j];
        }
    }
    
    for(int i=0;i<k;i++){
        for(int j=0;j<d[i];j++){
            have_o[a[i][j]] = true;
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(have_o[i] == false) ans++;
    }
    cout << ans << endl;
    
}