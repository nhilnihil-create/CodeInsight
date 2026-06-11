#include <bits/stdc++.h>
using namespace std;
int main(){
    long long h,w;
    cin >> h >> w;
    long long s = h*w;
    if(h==1||w==1){
        cout << 1 << endl;
        return 0;
    }else if(s%2!=0){
        cout << (s+1)/2 << endl;
    }else{
        cout << s/2 << endl;
    }
    return 0;
}