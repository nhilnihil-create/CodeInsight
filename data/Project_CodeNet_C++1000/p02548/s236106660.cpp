#include <bits/stdc++.h>
using namespace std;
int main(void){
    long n; cin >> n; 
    long cnt = 0;
    for(long i=1;i<1000000;i++){
        if(i >= n)break;
        for(long j=1;j<1000000;j++){
            if(i*j < n)cnt++;
            else break;
        }
    }
    cout << cnt << endl;
}
