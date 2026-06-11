#include<bits/stdc++.h>
using namespace std;
int main(){
	int N; cin>>N;
	vector<int> A(N);
	for (int i=0; i<N; i++)
		cin>>A[i];
	sort(A.begin(),A.end());
	int M=A.back()-A.front();
	for (int i=1; i<N-1; i++)
		M+=abs(A[i]);
	cout<<M<<endl;
	int x=A.front(), y=A.back();
	for (int i=1; i<N-1; i++) {
		if (A[i]<0) cout<<y<<" "<<A[i], y-=A[i];
		else cout<<x<<" "<<A[i], x-=A[i];
		cout<<"\n";
	}
	cout<<y<<" "<<x<<"\n";
	return 0;
}