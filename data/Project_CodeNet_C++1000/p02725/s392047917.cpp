#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int k,n;
    cin >> k >> n;
    vector<int> a(n+1);
    int maxi=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(i==0) continue;
        maxi=max(a[i]-a[i-1],maxi);
    }
    maxi=max(k+a[0]-a[n-1],maxi);
    cout << k-maxi << endl;
    return 0;    
}