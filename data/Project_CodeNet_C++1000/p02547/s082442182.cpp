#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n][2];
    for(int i=0; i<n; i++){
        cin >> a[i][0] >> a[i][1];
    }

    bool flag = false;
    for(int i=0; i<n-2; i++){
        if(a[i][0]!=a[i][1]) continue;
        if(a[i+1][0]!=a[i+1][1]) continue;
        if(a[i+2][0]!=a[i+2][1]) continue;
        flag = true;
        break;
    }
    if(flag){
        cout << "Yes";
    }else{
        cout << "No";
    }
}