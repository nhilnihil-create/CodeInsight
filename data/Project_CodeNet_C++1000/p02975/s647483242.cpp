#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cnt = a[0];
    for(int i = 1; i < n; i++){
        cnt = cnt ^ a[i];
    }
    if(cnt == 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}

