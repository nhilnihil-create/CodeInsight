#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;
int main(void){
    int k,n;
    cin >> k >> n;
    vector<int> A(n);
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    sort(A.begin(),A.end());
    int x=0;
    for(int i=1;i<n;i++){
        x = max(abs(A[i-1]-A[i]),x);
    }
    x = max(abs(k+A[0]-A[n-1]),x);
    cout << k-x << endl;
	return 0;
}