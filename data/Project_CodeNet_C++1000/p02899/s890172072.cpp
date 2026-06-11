#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main(void){
    int n;
    cin >> n;
    int a[n],b[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
	// for(int i=1;i<=n;i++){
    //     for(int j=0;j<n;j++){
    //         if(a[j]==i){
    //             b[i-1] = j+1;
    //         }
    //     }
    // }
    for(int i=0;i<n;i++){
        b[a[i]-1] = i+1;
    }
    
    for(int i=0;i<n;i++){
        cout << b[i] << " ";
    }
    cout << endl;
    return 0;
}