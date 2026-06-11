#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define MAX 100000
void inarray(int a[], int n){
    for(int i = 0; i < n; i++) cin >> a[i];
}
void zero(int a[], int n){
    for(int i = 0; i < n; i++) a[i] = 0;
}

int main(){
    int n; cin >> n;
    int a[n]; inarray(a,n-1);

    int ans[n]; zero(ans, n);

    for(int i = 0; i < n-1; i++){
        ans[a[i]-1]++;
    }

    for(int i = 0; i < n; i++){
        cout << ans[i] << endl;
    }
    return 0;
}