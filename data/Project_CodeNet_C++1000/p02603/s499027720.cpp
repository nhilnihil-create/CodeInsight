#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    long long ans = 1000;
    long long max = 1000;
    long long now = 0;
    int flag = 0;
    for(int i = 0; i < n - 1; i++){
        if(flag == 0){
            if(a[i] < a[i + 1]){
                now = max / a[i];
                max -= now * a[i];
                flag = 1;
            }
        }else{
            if(a[i] > a[i + 1]){
                max += now * a[i];
                if(ans < max){
                    ans = max;
                }else{
                    max = ans;
                }
                now = 0;
                flag = 0;
            }
        }
    }

    if(now != 0){
        max += now * a[n - 1];
        if(ans < max){
            ans = max;
        }
    }

    cout << ans << endl;
}