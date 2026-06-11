#include <bits/stdc++.h>
using namespace std;
int main(){
    long long x, a, b, i, j, f=0;
    cin >> x;
    for(i=-1000;i<=1000;i++){
        for(j=-1000;j<=1000;j++){
            if(x==(i*i*i*i*i)-(j*j*j*j*j)){
                f=1;
                a=i;b=j;
                break;
            }
        }
        if(f==1) break;
    }
    cout << a << " " << b <<endl;
    return 0;
}
