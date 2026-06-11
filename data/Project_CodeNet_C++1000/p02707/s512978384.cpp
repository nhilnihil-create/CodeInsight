#include<bits/stdc++.h> 
using namespace std;
using ll = long long;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int main() {
    fast_io;
    int n;
    cin>>n;

    int arr[n+1]={};
    
    //fill_n(arr, n+1, 0);

    for(int i=1;i<n;i++) {
        int n;
        cin>>n;

        arr[n]++;
    }

    for(int i=1;i<n+1;i++) {
        cout<<arr[i]<<endl;
    }

}


