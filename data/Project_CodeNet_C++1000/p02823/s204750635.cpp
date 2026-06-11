#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long int N,A,B;
	cin>>N>>A>>B;
	long long int temp=max(A,B)-min(A,B)-1;
	if(temp%2) cout<<temp/2+1<<"\n";
	else{
	    long long int ans1,ans2;
	    long long int a,b;
	    a=min(A,B);
	    b=max(A,B);
	    ans1=N-b;
	    a+=N-b;
	    b=N;
	    a++;
	    ans1++;
	    if(a!=b) ans1+=(b-a-1)/2+1;
	    a=min(A,B);
	    b=max(A,B);
	    ans2=a-1;
	    b-=a-1;
	    a=1;
	    b--;
	    ans2++;
	    if(a!=b) ans2+=(b-a-1)/2+1;
	    cout<<min(ans1,ans2)<<"\n";
	}
	return 0;
}