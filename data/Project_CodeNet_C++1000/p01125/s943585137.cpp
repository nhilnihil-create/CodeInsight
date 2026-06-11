#include<stdio.h>
int table[21][21];
char e[2];
int main(){
	int a;
	while(scanf("%d",&a),a){
		for(int i=0;i<21;i++)
			for(int j=0;j<21;j++)
				table[i][j]=0;
		for(int i=0;i<a;i++){
			int b,c;
			scanf("%d%d",&b,&c);
			table[b][c]=1;
		}
		int d;
		int x=10;
		int y=10;
		scanf("%d",&d);
		for(int i=0;i<d;i++){
			int f;
			scanf("%s%d",e,&f);
			if(e[0]=='N')
				for(int j=0;j<f;j++)
					table[x][++y]=0;
			if(e[0]=='S')
				for(int j=0;j<f;j++)
					table[x][--y]=0;
			if(e[0]=='E')
				for(int j=0;j<f;j++)
					table[++x][y]=0;
			if(e[0]=='W')
				for(int j=0;j<f;j++)
					table[x--][y]=0;
			table[x][y]=0;
		}
		bool ok=true;
		for(int i=0;i<=20;i++)
			for(int j=0;j<21;j++)
				if(table[i][j])ok=false;
		printf(ok?"Yes\n":"No\n");
	}
}