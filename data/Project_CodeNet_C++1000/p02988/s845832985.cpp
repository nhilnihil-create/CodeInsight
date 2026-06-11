#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int ar[n];
    int count = 0;
    for(int  i = 0; i < n; ++i){
        cin >> ar[i];
    }
    for(int  i = 1; i < n-1; ++i){
        if(ar[i]>ar[i+1] && ar[i]>ar[i-1] || ar[i]<ar[i+1] && ar[i]<ar[i-1]){
            continue;
        }else count++;
    }
    cout << count;
    return 0;
}