#include <bits/stdc++.h>

using namespace std;
int main() {
    int c,t,sum=0,a,b;
    cin >>t;
    int arr[t];
    for(int i=0;i<t;i++){
        cin >> arr[i];
        sum += arr[i];
    }
    a = sum;
    b=0;
    for(int i=0;i<t;i++){
        b += arr[i];
        c = sum-b;
        a = min(a, abs(b-c));
    }
    cout << a;
    
 }