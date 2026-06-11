#include <bits/stdc++.h>
using namespace std;
#define int   long long

int32_t main() {
    int n;
    cin>>n;
    int a[n];
    long double ans =1;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        ans = ans*a[i];
        if(ans-1000000000000000000 > 0){
			cout << "-1";
			return 0;
		}
    }
    cout<< (long long)ans;
}
