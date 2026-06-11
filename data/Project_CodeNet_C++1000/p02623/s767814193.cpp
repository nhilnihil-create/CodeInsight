#include<bits/stdc++.h>
using namespace std;

int a[200005], b[200005];
long long ca[200005], cb[200005];
 
int main()
{
    int n, m, k,ans;
    scanf("%d%d%d",&n, &m, &k);
    ca[0] = 0, cb[0] = 0;
    long long asum = 0, bsum = 0;
    for(int i = 0; i < n; i++){
    	scanf("%d",&a[i]);
    	asum += a[i];
    	ca[i+1] = asum;
    }
    for(int i = 0; i < m; i++){
    	scanf("%d",&b[i]);
    	bsum += b[i];
    	cb[i+1] = bsum;
    }
    int hi = m + n, lo = 0, mid;
    while(hi - lo > 3){
    	mid = (hi + lo)/2;
    	int flag = 0;
    	for(int i = 0; i <= mid; i++){
    		if((mid-i) > m) continue;
    		else if(i > n) break;
    		else{
    			if(ca[i] + cb[mid-i] <= k) flag++;
    		}
    	}
    	if(flag == 0) hi = mid;
    	else lo = mid;
    	ans = mid;
    }
    for(int i = hi; i >= lo; i--){
    	int flag = 0;
    	for(int j = 0; j <= i; j++){
    		if(i-j > m) continue;
    		else if(j > n) break;
    		else{
    			if(ca[j]+cb[i-j] <= k) flag++;
    		}
    	}
    	ans = i;
    	if(flag > 0) break;
    }
    printf("%d\n",ans);
}