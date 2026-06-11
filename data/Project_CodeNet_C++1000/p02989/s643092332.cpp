#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int x = n/2;
    int ans = a[x] - a[x-1];
    cout << ans << endl;
	return 0;
}