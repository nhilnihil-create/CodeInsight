#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e4 + 5;
const int maxm = 5e5 + 5;
const ll inf = 2147483647;
int n, m, k;
int a[101], b[101];
int main(){
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)cin>>a[i];
    for(int i = 1; i < n; i++){
        b[i] = a[i] - a[i - 1];
    }
    ll sum = 1000, k;
    for(int i = 1; i < n; i++){
        if(b[i] <= 0)continue;
        k = sum / a[i - 1];
        sum += (k * b[i]);
    }
    cout<<sum;
    return 0;
}
