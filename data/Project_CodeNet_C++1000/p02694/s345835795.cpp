#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define MAX 100000
void inarray(int a[], int n){
    for(int i = 0; i < n; i++) cin >> a[i];
}

int main(){
    ll ch = 100;
    ll x; cin >> x;
    int i;
    for(i = 0; ch < x; i++){
        ch += ch/100;
    }
    cout << i << endl;
    return 0;
}