#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
		cin >> n;
		vector<int> a(n,0);
		vector<int> b(n,0);
		vector<int> c(n,0);
		for (int i=0;i<n;i++){
			cin >> a[i];
			cin >> b[i];
		}
		for (int i=0;i<n;i++){
			if (a[i]==b[i]){
				c[i]=1;
			}
		}
		int f=0;
		int f2=-1;
		for (int i=0;i<n;i++){
			if (c[i]==1){
				f=f+1;
			}
			else {
				f=0;
			}
			if (f==3){
				f2=1;
				break;
			}
		}
		if (f2==1){
			cout << "Yes";
		}
		else {
			cout << "No";
		}
    return 0;
}
