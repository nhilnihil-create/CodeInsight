#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
/*
time:
wa:
反省:
考察:
*/
int main() {
    int n; cin >> n;
    vector<int>b(n-1);
    vector <int>a(n);
    for(int i = 0; i < n-1; i++) cin >> b[i];
    a[0] = b[0];
    a[1] = b[0];
    for(int i = 1; i < n-1; i++){
        a[i+1] = b[i];
        if(b[i] < max(a[i+1], a[i])){
            a[i] = b[i];
        } 
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
    }
    cout << sum << endl;

    return 0;
}