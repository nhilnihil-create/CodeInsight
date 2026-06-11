#include<bits/stdc++.h>

using namespace std;

int main(){
    long n,r;
    cin >> n >> r;
    long cnt = 0;
    while(n!=0){
       n = n/r;
       cnt++;
    }
    cout << cnt << endl;
    return 0;
}