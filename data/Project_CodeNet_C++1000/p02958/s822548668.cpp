#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int a[n], b[n];

	for(int i=0; i<n; i++){
        cin>>a[i]; b[i]=a[i];
    }


	sort(a, a+n);


 

	int c=0;
	for(int i=0; i<n; i++) if(a[i]!=b[i]) c++;

	if(c==2 || c==0) cout<<"YES";
	else cout<<"NO";


}
