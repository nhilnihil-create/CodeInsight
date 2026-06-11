#include<bits/stdc++.h>
using namespace std;
int m,n;
bool ch(int x){while (x!=1){if (x%2)return 0;x/=2;}return 1;}
void sc(int x,int y){cout<<x<<' '<<y<<'\n';}
int lo(int x){return x&(-x);}
int main(){
	cin>>n;
	if (ch(n))puts("No");
	else{
		puts("Yes");
		sc(1,2);sc(2,3);sc(3,n+1);sc(n+1,n+2);sc(n+2,n+3);
		for (int i=4;i<=n;i+=2){
			if (i<n)sc(i,1),sc(i+1,1),sc(i+n,i+1),sc(i+n+1,i);
			else sc(i,i-lo(i)+1),sc(i+n,lo(i));
		}
	}
	return 0;
}