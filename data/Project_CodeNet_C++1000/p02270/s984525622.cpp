#include <cstdio>
#include <algorithm>
#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)<(b))?(a):(b)
using namespace std;


int main() {
	int n,p,q,r,max=-1,w;
	int i,j;
	int c;
	int *sum;
	int p_under;
	int p_over;
	bool flag=false;
	scanf("%d%d",&n,&q);
	sum=(int *)malloc(sizeof(int)*n);
	scanf("%d",&w);
	max=sum[0]=w;
	for(i=1; i<n; ++i) {
		scanf("%d",&w);
		max=MAX(w,max);
		sum[i]=sum[i-1]+w;
	}
	if(q==1) {
		printf("%d\n",sum[n-1]);
		return 0;
	}
	p=max;
	p_over=sum[n-1];
	p_under=0;
	while(1) {
		i=0;
		for(c=0; c<q-1; ++c) {
			for(j=0; i+j<n; ++j) {
				if(i==0) {
					if(sum[j]>p) {
						i=j;
						j=0;
						break;
					}
				} else {
					if(sum[i+j]-sum[i-1]>p) {
						i+=j;
						j=0;
						break;
					}
				}
			}
			if(i+j==n-1 && c<q-2) {
				if(p==max || flag) {
					printf("%d\n",p);
					return 0;
				}
				p_over=MIN(p_over,p);
				if(flag) {
					++p;
				} else {
					p=(p_under+p_over)/2;
				}
			}
		}
		r=sum[n-1]-sum[i-1];
		if(r==p) {
			printf("%d\n",p);
			return 0;
		} else if (!flag) {
			if(r<p) {
				p_over=MIN(p_over,p);
				p=(p_over+p_under)/2;
			} else if(r>p) {
				if(p_over-p_under<=10 || r-p<=10 ) {
					flag=true;
					p_under=MAX(p_under,p);
					++p;
				} else {
					p_under=MAX(p_under,p);
					p=(p_under+p_over)/2;
				}
			}
		} else {
			if(r>p) {
				++p;
			} else {
				printf("%d\n",p);
				return 0;
			}
		}
	}
	return 0;
}