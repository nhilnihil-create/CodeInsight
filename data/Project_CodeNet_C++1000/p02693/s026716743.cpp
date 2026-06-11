#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define MAX 100000
void inarray(int a[], int n){
    for(int i = 0; i < n; i++) cin >> a[i];
}

int main(){
    int k,a,b; cin >> k >> a >> b;
    if(k * (b/k) >= a) cout << "OK" << endl;
    else cout << "NG" << endl;
    return 0;
}