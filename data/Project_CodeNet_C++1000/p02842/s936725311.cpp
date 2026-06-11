#include <bits/stdc++.h>
using namespace std;
int main(void){
    long double n;
    cin>>n;
    int flag=0;
    for (int i=1;i<=50000;i++) {
        if (floor(i*1.08)==n) {
            cout<<i<<endl;
            flag=1;
            break;
        }
    }
    if (flag==0) {
        cout<<":("<<endl;
    }
}