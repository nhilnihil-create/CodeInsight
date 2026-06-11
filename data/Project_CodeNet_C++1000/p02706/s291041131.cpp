#include <iostream>
#include<stdio.h>
using namespace std;
#define int long long

signed main(){
    // Your code here!
    int n,m,o;
    int a[10001];
    
    o = 0;
    
    cin >> n >> m;
    for(int i = 0; i < 10001; i ++){
        a[i] = 0;
    }
    for(int s=0; s < m ;s++){
        cin >> a[s];
        o+=a[s];
    }
    if(n>=o){
        cout << n-o;
    }else{
        printf("-1");
    }
    
}
