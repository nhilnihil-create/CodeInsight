#include <bits/stdc++.h>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){
    int n;cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    sort(arr,arr+n);

    int mid1 = arr[n/2-1];
    int mid2 = arr[n/2];

    //cout << mid1 << endl;
    //cout << mid2 << endl;

    int ans = 0;

    if(mid1 < mid2){
        for(int i=mid1+1;i<=mid2;i++){
            ans++;
        }
    }

    cout << ans << endl;
}