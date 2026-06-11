#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> c(n);
    for (int i = 0; i < n; i++){
        c[i] = a[i];
    }
    sort(c.begin(),c.end());

    for (int i = 0; i < n; i++){
            if (a[i] == c[n-1]){
                cout << c[n-2] << endl;
            }
            else{
                cout << c[n-1] << endl;
            }
    }

    
}