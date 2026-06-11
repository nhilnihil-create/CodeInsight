#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int W,H;
int divW[1501*1000];
int divH[1501*1000];
int w[1502];
int h[1502];

main(){
	int i,j,k;
	while(cin>>H>>W, H){
		fill(divW, divW+W*1000, 0);
		fill(divH, divH+H*1000, 0);
		for(i=1;i<=H;i++){
			cin>>h[i];
			h[i] += h[i-1];
			for(j=0;j<i;j++) divH[h[i]-h[j]]++;
		}
		for(i=1;i<=W;i++){
			cin>>w[i];
			w[i] += w[i-1];
			for(j=0;j<i;j++) divW[w[i]-w[j]]++;
		}
		int ans = 0;
		for(i=0;i<=w[W]&&i<=h[H];i++) ans+= divH[i]*divW[i];
		cout<<ans<<endl;
	}
	return 0;
}