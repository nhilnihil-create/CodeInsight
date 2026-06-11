#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    const int rate = 8;
    int low = 0;
    int high = 9999999;
    while(1){
        if(low == high-1){
            break;
        }
        int mid = (low + high) / 2;
        int ans = ((mid * rate) / 100) + mid;
        if(ans == n){
            cout<<mid<<endl;
            return 0;
        }
        else if(ans > n){
            high = mid;
        }
        else
            low  = mid;
    }
    cout<<":("<<endl;
    return 0;
}