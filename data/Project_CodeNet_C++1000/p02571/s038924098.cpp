#include<bits/stdc++.h>
using namespace std;

char a[1005];
char b[1005];

int main()
{
	scanf("%s%s",a+1,b+1);
	int len1 = strlen(a+1),len2 = strlen(b+1);
	int ans = len2;

	int n = len1-len2+1;
	for(int i = 1;i<=n;++i){
		int sum = 0;
		for(int j = 1;j<=len2;++j){
			if(a[i+j-1] == b[j]) sum++;
		}
		if(len2-sum<ans) ans = len2-sum;
	}
    cout<<ans<<endl;
    return 0;
}