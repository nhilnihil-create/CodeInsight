#include <bits/stdc++.h>
using namespace std;
int main(void){
    int k,a=7;
    cin >> k;
    for(int i=1;i<=k;i++){
        if(a%k==0){
            cout << i << endl;
            return 0;
        } 
        else a = (a*10+7)%k;
    }
    cout << -1 << endl;
}
