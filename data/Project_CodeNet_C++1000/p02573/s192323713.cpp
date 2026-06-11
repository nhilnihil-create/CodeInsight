#include<stdio.h>
int binc[2000005],kind[2000005];
int find(int x){
	if(binc[x]==x) return x;
	binc[x]=find(binc[x]);return binc[x];
}
void together(int a,int b){
	int ax=find(a),bx=find(b);
	if(ax==bx) return ;
	binc[bx]=ax;
}
int main(){
	int n,m,a,b,max=-1;
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++) binc[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		together(a,b);
	}
	for(int i=1;i<=n;i++) kind[find(i)]++;
	for(int i=1;i<=n;i++) if(kind[i]>max) max=kind[i];
	printf("%d",max);
	return 0; 
}