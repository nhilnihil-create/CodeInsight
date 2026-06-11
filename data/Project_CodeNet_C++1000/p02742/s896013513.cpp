#include<bits/stdc++.h>
using namespace std;
using lli = long long;

lli h, w;

int main(void){
    cin >> h >> w;
    if(h == 1 || w == 1) cout << 1 << endl;
    else if(h*w%2 == 0){
        cout << h*w/2 << endl;
    }else{
        cout << (h*w+1)/2 << endl;
    }
    return 0;
}
