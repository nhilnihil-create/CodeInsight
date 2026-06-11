#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)cin >> a[i];
    long const mod = 1e9+7;

    int h = 0;
    int m = 0;
    int l = 0;

    long ans = 1;

    for(int i=0;i<n;i++){
        // printf("%ld %ld %ld %ld %ld\n",h,m,l,a[i],ans);
        if(a[i] == h){
            if(a[i] == m){
                if(a[i] == l){
                    ans *= 3;
                }else{
                    ans *= 2;
                }
            }
            h++;
        }else{
            if(a[i] == m){
                if(a[i] == l){
                    ans *= 2;
                }
                m++;
            }else{
                if(a[i] == l){
                    l++;
                }else{
                    ans = 0;
                    break;
                }
            }
        }

        ans %= mod;
    }
    cout << ans << endl;
}