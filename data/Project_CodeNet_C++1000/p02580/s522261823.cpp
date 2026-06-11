#include<bits/stdc++.h>
using namespace std;
long long int H,W,M,a,b,mah,maw,n[300001],m[300001],ma=0,n1=0,m1=0,h[1000000],w[1000000];
int main() {
	cin>>H>>W>>M;
	for (int i=1; i<=M; i++) {
		cin>>n[i]>>m[i];
		h[n[i]]+=1;
		w[m[i]]+=1;
	}
	a=0;
	b=0;
	for (int i=1; i<=H; i++)
		if (h[i]>mah)
			mah=h[i];
	for (int i=1; i<=H; i++)
		if (h[i]==mah) {
			a++;

		}

	for (int j=1; j<=W; j++)
		if (w[j]>maw)
			maw=w[j];
	for (int i=1; i<=W; i++)
		if (w[i]==maw) {
			b++;

		}
	ma=a*b;

	for (int z=1; z<=M; z++)
		if ((h[n[z]]==mah)&&(w[m[z]]==maw)) m1++;

	if (ma==m1)
		cout<<maw+mah-1;
	else cout<<maw+mah;
	return 0;
}