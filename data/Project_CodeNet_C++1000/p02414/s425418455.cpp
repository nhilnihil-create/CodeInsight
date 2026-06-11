#include<cstdio>

int main(void){
int i,j,k,n,m,l,nm,ml,nl;
scanf("%d%d%d",&n,&m,&l);
nm=n*m;
ml=m*l;
nl=n*l;

int a[nm],b[ml];
long long c[nl]={0};
for (i=0;i<nm;i++){
	scanf("%d",&a[i]);
};
for(i=0;i<ml;i++){
	scanf("%d",&b[i]);
};

for(i=0;i<n;i++){
	for(j=0;j<l;j++){
		for(k=0;k<m;k++){
			c[i*l+j]=c[i*l+j]+a[i*m+k]*b[k*l+j];
		};
	};
};

for(i=0;i<n;i++){
	for(j=0;j<l-1;j++){
		printf("%lld ",c[i*l+j]);
	};
	printf("%lld\n",c[i*l+l-1]);
};

return 0;
}