#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    long long a[100005];
    for(long long i=0;i<n;i++) cin >> a[i];
    long long sum=a[0];
    for(long long i=1;i<n;i++) sum=sum^a[i];
    if(sum==0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
