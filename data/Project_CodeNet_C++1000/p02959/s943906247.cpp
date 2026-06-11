#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<long long> a(n+1);
    for(int i=0; i<n+1; i++){
        cin >> a[i];
    }
    vector<long long> b(n);
    for(int i=0; i<n; i++){
        cin >> b[i];
    }
    long long ans=0;
    long long tmp1, tmp2;
    for(int i=0; i<n; i++){
        tmp1 = min(a[i],b[i]);
        b[i] = b[i] - tmp1;
        tmp2 = min(a[i+1],b[i]);
        a[i+1] = a[i+1] - tmp2;
        ans = ans + tmp1 + tmp2;
    }
    cout << ans << endl;
}

