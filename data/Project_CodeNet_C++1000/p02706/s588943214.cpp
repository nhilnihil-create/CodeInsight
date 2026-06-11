#include <iostream>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <algorithm>
#include <bits/stdc++.h>
#define MOD 1000000000
#define ll long long
#define mm(arr) memset(arr, 1, sizeof(arr))
#define scanArray(a,n) for(ll i = 0; i < n; i++){cin >> a[i];}
#define PI 3.141592653589793
using namespace std;
int main(){
FAST
int n,m; cin >> n >> m;
int a[n];
int sum2=0;
for(int i =0; i<m; i++){
    cin >> a[i];
    sum2+=a[i];

}
if(n>=sum2){
    cout << n-sum2<< endl;
}
else{
    cout << "-1" << endl;
}

return 0;
}
