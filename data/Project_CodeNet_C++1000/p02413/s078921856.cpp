#include<cstdio>

int main(void){
int i,j,m,n,mn;
scanf("%d%d",&n,&m);
mn=m*n;
int a[mn],b[n]={0},c[m]={0},d=0;
for (i=0;i<mn;i++){
	scanf("%d",&a[i]);
};
for(i=0;i<n;i++){
	for(j=0;j<m;j++){
		b[i]=b[i]+a[i*m+j];
	};
};
for(i=0;i<m;i++){
	for(j=0;j<n;j++){
		c[i]=c[i]+a[j*m+i];
	};
};
for(i=0;i<n;i++){
	d=d+b[i];
}
for(i=0;i<n;i++){
	for(j=0;j<m;j++){
		printf("%d ",a[i*m+j]);
	};
	printf("%d\n",b[i]);
};
for(i=0;i<m;i++){
	printf("%d ",c[i]);
};
printf("%d\n",d);


return 0;
}