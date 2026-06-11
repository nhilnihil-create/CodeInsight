#include <bits/stdc++.h>
using namespace std;
#define rep(i,x) for(int i=0;i<x;i++)
 
int main(){
    long long h,w,m,ans(0);
    cin >> h >> w;
 
    m = h*w;
 
    if(h==1||w==1){
        puts("1");
        return 0;
    }
 
    if(m%2==0){
        cout << m/2 << endl;
        return 0;
    }else{
        cout << m/2+1 << endl;
        return 0;
    }
}