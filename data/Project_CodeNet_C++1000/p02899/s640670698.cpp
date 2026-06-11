#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
    }
    vector<int> b(n);
    for(int i = 0; i < n; i++)
        b[a[i]] = i;
    for(int i = 0; i < n; i++)
        cout << b[i] + 1 << " ";
    return 0;
}