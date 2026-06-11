#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int ans=(n-400)/200+1;
	ans=9-ans;
	printf("%d",ans);
	return 0;
}