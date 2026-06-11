#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(float i=0;i<=50000;i++){
        if(n==int(i*1.08)){
            cout<<i<<endl;
            break;
        }
        if(i==50000||n<int(i*1.08)){
            cout << ":(" <<endl;
            break;
        }
    }
    return 0;
}