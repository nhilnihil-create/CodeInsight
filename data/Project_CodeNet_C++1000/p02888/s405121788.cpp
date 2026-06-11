#include<bits/stdc++.h>
using namespace std;
const int M=2e3+5;

int n,l[M];
long long tot=0;

bool check(int a,int b,int c){
	if (a+b>c && b+c>a && c+a>b) return true;
	return false;
}

int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>l[i];
	}
	sort(l+1,l+n+1);
	for (int i=1;i<=n-2;i++){
		for (int j=i+1;j<=n-1;j++){
			int lf=j+1,rt=n,mid;
			if (lf>rt) break;
			while (lf!=rt){
				mid=(lf+rt)/2;
				if (check(l[i],l[j],l[mid])){
					lf=mid+1;
				} else {
					rt=mid;
				}
			}
			tot+=(rt-j-1);
			if (check(l[i],l[j],l[rt])) tot++;
		}
	}
	cout<<tot;
	return 0;
}
