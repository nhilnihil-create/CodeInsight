#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    double ans = v[0];
    for(int i=1;i<n;i++){
        ans = (ans+v[i])/2;
    }
    cout << ans << endl;
	return 0;
}