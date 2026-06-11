#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

int logs[200005];

int main(){
    int n, k; cin>>n>>k;
    int maxl = 0;
    for(int i = 0; i < n; i++){
        cin>>logs[i];
        maxl = max(maxl, logs[i]);
    }
    long long l = 1, r = maxl, mid = (l + r) / 2;
    while(l != r){
        int res = 0;
        for(int i = 0; i < n; i++){
            if(logs[i] > mid){
                res += logs[i] / mid;
            }
        }
        if(res > k){
            l = mid + 1;
        }
        else{
            r = mid;
        }
        mid = (l + r) / 2;
    }
    cout<<l<<endl;
}
