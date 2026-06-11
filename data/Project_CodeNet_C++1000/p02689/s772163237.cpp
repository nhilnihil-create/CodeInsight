#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n,m; cin >> n >> m;
    long long int h[n+1];
    for(int i=0;i<n;i++){
        cin >> h[i];
    }
    int a[m+1];
    int b[m+1];
    int cnt[n+1];
    for(int i=0;i<n;i++){
        cnt[i] = 0;
    }
    for(int i=0;i<m;i++){
        cin >> a[i] >> b[i];
    }
    for(int i=1;i<=m;i++){
        if(h[a[i-1]-1]>h[b[i-1]-1]){
            cnt[b[i-1]-1] += 1;
        }
        else if(h[a[i-1]-1]==h[b[i-1]-1]){
            cnt[a[i-1]-1] += 1;
            cnt[b[i-1]-1] += 1;
        }
        else{
            cnt[a[i-1]-1] += 1;
        }
      //  cout << h[a[i-1]-1] ;
    }
   /* for(int i=0;i<n;i++){
        cout << cnt[i] << endl;
    }*/
    int ans=0;
    for(int i=0;i<n;i++){
        if(cnt[i]==0){
            ans += 1;
        }
    }
    cout << ans << endl;
}



