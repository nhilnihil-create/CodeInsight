#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,cnt = 0;
    cin >> n;
    int arr[n];
    for(int i=0; i <n ; ++i){
        cin >> arr[i];
    }
    for( int k=1; k < n-1; ++k){
        if((arr[k]<arr[k+1]&&arr[k]>arr[k-1]) || (arr[k]>arr[k+1]&&arr[k]<arr[k-1])){
            ++cnt;
        }
    }
    cout<< cnt;
    return 0;
}
