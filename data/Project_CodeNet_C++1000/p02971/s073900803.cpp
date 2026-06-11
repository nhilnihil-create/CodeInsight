#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
  b=a;
    sort(a.begin(),a.end());
    int m1=a[n-1],m2=a[n-2];
    for(int i=0;i<n;i++){
    if(b[i]==m1)cout<<m2<<endl;
    else cout<<m1<<endl;
    }
    return 0;
}