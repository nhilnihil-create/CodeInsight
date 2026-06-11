#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector <int> a(n,0);
    bool isDenied = false;
    for(int i = 0; i<n; i++){
        cin >> a[i];
        if(a[i]%2==0){
            if(a[i]%3==0){
                continue;
            }
            if(a[i]%5==0){
                continue;
            }
            isDenied = true;
            break;
        }
    }
    if(isDenied==true){
        cout << "DENIED" <<endl;
    }else{
        cout << "APPROVED" <<endl;
    }
    
    return 0;
}