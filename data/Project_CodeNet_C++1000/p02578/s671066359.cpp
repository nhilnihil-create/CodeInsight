#include <bits/stdc++.h>

using namespace std ;

int main(){
    int a ;
    cin >> a ;
    long long int n[a] ;
    long long int sum = 0 ;
    for(int i=0;i < a;i++){
        cin >> n[i] ;
        if(i > 0 && n[i] < n[i-1]){
            sum += n[i-1] - n[i] ;
            n[i] = n[i-1] ;
    }
    }
    cout << sum << endl ;
    return 0 ;
    }
