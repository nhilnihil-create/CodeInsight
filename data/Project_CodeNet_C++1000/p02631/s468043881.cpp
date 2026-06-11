#include<bits/stdc++.h>
using namespace std;
int n;

int main(){
    cin >> n;
    int a[n]; for(int i=0; i<n; i++) cin >> a[i];
    int x = 0; for(int i=0; i<n; i++) x^=a[i];
    for(int i=0; i<n; i++) cout << (x^a[i]) << " ";
}
