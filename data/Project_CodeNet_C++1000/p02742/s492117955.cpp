#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, k) for (int i = (s); i < (int)(k); i++)

int main(){
    long long h,w,ans;
    cin >> h >> w;
    if(h==1||w==1){
        ans = 1;        
    }else if(w%2==0){
        ans = h*w/2;
    }else{
        if(h%2==0){
            ans = h*w/2;
        }else{
            ans = w*(h-1)/2+(w+1)/2;
        }
    }
    cout << ans << endl;
}