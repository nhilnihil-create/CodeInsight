#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, mini ;
    long long minc = 0;
    cin >> n;
    int arr[n];
    for(int i =0 ; i < n; ++i){
        cin >> arr[i]; 
    }
    for(int p = 0; p < n ; ++p){
        minc = 0;
        for(int k = 0; k <= p ; ++k){
            minc += arr[k];
        }
        for(int z = 0; z < (n-1-p) ; ++z){
            minc -= arr[n-1-z];
        }
        if(p==0){
            mini = abs(minc);
        } 
        if(abs(minc)<mini){
            mini = abs(minc);
        }
    }
    cout<< mini;
    return 0 ;
}