#include<cstdio>

int main(){
	int sen[10000],bit[1024],num[1024][11],s,i,j,r,c,cc;
	for(int r=1;r<11;r++){
		for(i=0;i<2<<r;i++){
			for(num[i][r]=0,s=i;s>0;s >>= 1)num[i][r]+=s&1;
			if(num[i][r]<r/2) num[i][r] = r-num[i][r];
		}
	}

  while(1){
		scanf("%d %d",&r,&c);
		if (!r)break;
		for(i=0;i<c;i++) sen[i] = 0;
		for(j=0;j<r;j++){
			for(i=0;i<c;i++){
				scanf("%d",&cc);
				sen[i] <<= 1;
				sen[i] += cc;
			}
		}
		for(i=0;i<1024;i++) bit[i] = 0;
		for(i=0;i<c;i++) bit[sen[i]]++;

		int n,sum = 0,smax = 0,k=1;
		k <<= r-1;
		for(i=0;i<k;i++){
			sum = 0;
			for(j=0;j<k<<1;j++){
				s = j^i;
				sum += num[s][r] * bit[j];
			}
			if (sum>smax)smax = sum;
		}
		printf("%d\n",smax);
  }
  return 0;
}