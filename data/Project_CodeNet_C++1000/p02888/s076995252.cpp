#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n,i,j;
  	long long ans=0;
    cin >> n;
    vector<long long> v(n);
  	for(i=0;i<n;i++) cin >> v[i];
    sort(v.begin(),v.end());

    vector<long long> v2(1010);
    for(i=0;i<1010;i++) v2[i] = 0;
    for(i=0;i<n;i++) v2[v[i]] += 1;
    for(i=1;i<1010;i++) v2[i] = v2[i-1]+v2[i];
	
  	/*
    for(int i=0;i<1010;i++) {

        cout << v2[i] << " ";
    }
    cout << endl;*/

    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
          	if(i==j) continue;
          	long long c=0;
            long long mx = min((long long)1010,v[i]+v[j])-1;
            long long mn = max(v[i],v[j]) - min(v[i],v[j]);
          	c += (v2[mx] - v2[mn]);
          	
          	if(v[i] <= mx && mn < v[i]) c-=1;
          	if(v[j] <= mx && mn < v[j]) c-=1;
          	ans+=max((long long)0,c);
        }
    }
 	cout << ans/6 << endl;
}
//