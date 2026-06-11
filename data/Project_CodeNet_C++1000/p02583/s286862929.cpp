//BISMILLAH
#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int i,j,n,cnt = 0,k;
    cin >> n;
    long long int a[n];
    for(i = 0;i<n;i++) cin >> a[i];
    for(i = 0;i<n-2;i++){
        for(j = i+1;j<n-1;j++){
            if(a[i] != a[j]){
            for(k = j + 1;k<n;k++){
                if(a[k] != a[j] && a[k] != a[i]){
                    if(a[i] + a[j] > a[k] && a[j] + a[k] > a[i] && a[i] + a[k] > a[j]) cnt++;
                }
            }
          }
        }
    }
       cout << cnt << endl;
    return 0;
}