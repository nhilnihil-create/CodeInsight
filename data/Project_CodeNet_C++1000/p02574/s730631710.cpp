#include<bits/stdc++.h>
#define int long long
#define rep1(i,a,b) for(int i=a;i<b;i++)
#define rep2(i,a,b) for(int i=a;i>=b;i--)
#define mod 1000000007
#define garou ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
signed main() {
garou;
	vector<int> v1(1000001,0);
int n;
cin>>n;
vector<int> v(n,0);
rep1(i,0,n)
cin>>v[i];
int x=0;
rep1(i,0,n){
	for(int j=2;j*j<=v[i];j++){
		if(v[i]%j==0){
			v1[j]++;
			if((j*j)!=v[i])
			v1[v[i]/j]++;
			if((v1[j]>=2||v1[v[i]/j]>=2)&&v[i]/j>1){
				x=-1;
				break;
			}
		}
	}
		v1[v[i]]++;
		if(v1[v[i]]>=2&&v[i]>1){
			x=-1;
			break;
		}
	if(x==-1)
	break;
}
if(x==0){
	cout<<"pairwise coprime";
	return 0;
}
int g=v[0];
rep1(i,1,n)
g=__gcd(g,v[i]);
if(g==1){
	cout<<"setwise coprime";
	return 0;
}
cout<<"not coprime";
	}