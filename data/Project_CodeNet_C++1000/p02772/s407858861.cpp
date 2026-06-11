#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    bool flag = true;
    for(int i=0; i<n; i++){
        if(a[i] % 2 == 0 
        && a[i] % 3 != 0 
        && a[i] % 5 != 0){
            cout << "DENIED" << endl;
            return 0;
        }
    }
    cout << "APPROVED" << endl;
    return 0;
}