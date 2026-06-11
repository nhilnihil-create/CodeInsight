#include<stdio.h>

int main(){
	
	int a[7],b,x,y,z,c[7];
	
	for(int i=0;i<6;i++){
		
		scanf("%d",&a[i]);
		c[i]=a[i];
	}
	scanf("%d",&b);
	
	for(int i=0;i<b;i++){
		///a????????¨?????????///
		for(int i=0;i<6;i++){
			a[i]=c[i];
		}
		
		scanf("%d %d",&x,&y);
		
		
		/////////??????x?????????/////////
		
		for(int i=0;x!=a[0];i++){
			if(i==4) break;
			z=a[0];
			a[0]=a[4];
			a[4]=a[5];
			a[5]=a[1];
			a[1]=z;
		}
		if(x!=a[0]){
			for(int i=0;x!=a[0];i++){
				if(i==4) break;
				z=a[0];
				a[0]=a[2];
				a[2]=a[5];
				a[5]=a[3];
				a[3]=z;
			}
		}
		//printf("%d\n\n",a[0]);
		
		/////////?????????y?????????/////////
		
		for(int i=0;y!=a[1];i++){
			if(i==4) break;
			
			z=a[1];
			a[1]=a[3];
			a[3]=a[4];
			a[4]=a[2];
			a[2]=z;
		}
		//printf("%d\n\n",a[1]);
		
		printf("%d\n",a[2]);
	}
	return 0;
}
	