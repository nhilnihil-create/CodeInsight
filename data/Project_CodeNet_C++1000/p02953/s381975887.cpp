#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    bool b = true;
    cin >> n;
    vector<long> v(n);
    for(int i=0;i<n;i++)cin >> v[i];
    v[0]--;
    for(int i=1;i<n;i++){
        if(v[i] > v[i-1])v[i]--;
        else if(v[i] < v[i-1]){
            cout << "No" << endl;
            b = false;
            break;
        }
    }
    if(b)cout << "Yes" << endl;
}