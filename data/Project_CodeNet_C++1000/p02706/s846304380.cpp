#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define MAX 100000
void inarray(int a[], int n){
    for(int i = 0; i < n; i++) cin >> a[i];
}

int main(){
    int n,m; cin >> n >> m;
    int sum = 0;
    for(int i = 0; i < m; i++){
        int a; cin >> a;
        sum += a;
    }
    int ans = (n-sum >= 0) ? n-sum : -1;
    cout << ans << endl;
    return 0;
}