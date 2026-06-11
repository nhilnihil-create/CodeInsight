#include <fstream>
#include <iostream>
#include <vector>
#include <numeric>
#include<algorithm>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int n,m,k,c;
    cin >> n >> m >> k;
    vector<long int> a(n+1);
    vector<long int> b(m+1);
    a[0] = b[0] =0;
    rep(i,n){
        cin >> a[i+1];
        a[i+1] +=a[i];
    }
    rep(i,m){
        cin >> b[i+1];
        b[i+1] += b[i];
    }
    int ans=0,j=0;
    rep(i,n+1){
        if(k-a[i]<0) break;
        while(b[j]<=k-a[i]){
            j++;
            if(j==m+1) break;
        }
        j--;
        // cout<< j << " i " << i << endl;
        ans = max(ans,i+j);
    }
    
    cout << ans << endl;
}