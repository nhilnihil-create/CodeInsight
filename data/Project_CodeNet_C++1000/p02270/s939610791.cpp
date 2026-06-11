#include <bits/stdc++.h>

using namespace std;

bool c(int x,int n,int k,vector<int> &w){
    int t;
    for(int i = 0 ; i < n ; i++,k--){
        t = 0;
        if(w[i] > x) return false;
        while(i < n && t + w[i] <= x){
            t += w[i++];
        }
        i--;
    }
    return (k >= 0);
}

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> w(n);
    for(int i = 0 ; i < n ; i++){
        cin >> w[i];
    }
    int l = 0, r = 1000000000;
    while(r-l > 0){
        int mid = (l + r) / 2;
        if(c(mid,n,k,w)){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    cout << r << endl;
    return 0;
}