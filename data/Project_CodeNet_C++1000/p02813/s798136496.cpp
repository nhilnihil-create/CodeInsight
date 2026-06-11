#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    vector<long long> p(n),q(n),perm(n);
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    for(int i=0;i<n;i++){
        cin>>q[i];
    }
    for(int i=0;i<n;i++){
        perm[i]=i+1;
    }
    long long a,b,cnt=0;
	do{
		cnt++;
		if(p==perm) a=cnt;
		if(q==perm) b=cnt;
	}while(next_permutation(perm.begin(),perm.end()));
	cout<<abs(a-b)<<endl;
    return 0;
}
