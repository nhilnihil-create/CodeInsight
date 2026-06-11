#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n, l, i, sum(0);
    cin>>n>>l;
    int f[n+1], m = INT_MAX, choosedapple(0);
    for (i = 1; i <= n; i++){
        f[i] = l+i-1;
        sum += f[i];
        if (abs(f[i]) < m){
            m = abs(f[i]);
            choosedapple = f[i];
        }
    }
    cout<<sum-choosedapple;
    return 0;
}