#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    for(int i=0; i<n; i++){
        cin >> a.at(i);
    }
    b=a;
    sort(a.begin(),a.end());
    for(int i=0; i<n; i++){
        if(a.at(n-1)-b.at(i)) cout << a.at(n-1) << endl;
        else cout << a.at(n-2) << endl;
//        cout << b.at(i) << endl;
    }
}