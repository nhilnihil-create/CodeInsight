#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, l, sum =0;
    cin >> n >> l;
    for(int i = l; i <= l+n-1; ++i ){
        sum += i;
    }
    if(l<=0 && sum >=0){
        cout << sum;
    }
    else if(l <= 0 && sum< 0){
        cout << sum - (l+n-1);
    }
    else{
        cout << sum-l;
    }
    return 0 ;
}