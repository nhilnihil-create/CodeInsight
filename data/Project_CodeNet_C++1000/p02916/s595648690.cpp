#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, ans =0;
    cin >> n;
    int a[n],b[n],c[n-1];
    for(int i =0 ; i <n ;++i){
        cin >> a[i];
    }
    for(int j =0 ; j <n ;++j){
        cin >> b[j];
    }
    for(int l =0 ; l <n-1 ;++l){
        cin >> c[l];
    }
    for(int k = 0; k <n; ++k){
        int z = a[k];
        ans += b[z-1];
        if(k!=0){
            int y = a[k-1], x=a[k] ;
            if(x == y + 1){
                ans += c[y-1] ;
            }
        }
    }
    cout<<ans;


}

