#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<locale.h>
#include<math.h>
#include<set>
#include<stack>
#include<queue>
using namespace std;
int main()
{
int h,w,kz,bc=0,ans=0;
string c[7];
scanf("%d %d %d",&h,&w,&kz);
for(int i=0;i<h;i++)
{
 cin >> c[i];
	for(int j=0;j<w;j++)
	{
	 if(c[i][j]=='#'){bc++;}
	}
}
for(int i=0;i<pow(2,h);i++)
{
	for(int j=0;j<pow(2,w);j++)
	{
	 int elm=0;
	 //iは行を、jは列を指す
	 int si=i,sj=j;
 	 int elmh[7]={},elmw[7]={};
	 for(int k=(h-1);k>=0;k--)
	 {
	  if(si>=pow(2,k)){elmh[k]=1; si-=pow(2,k);}
	 }
	 for(int k=(w-1);k>=0;k--)
	 {
	  if(sj>=pow(2,k)){elmw[k]=1; sj-=pow(2,k);}
	 }
	 //消す行と列を管理
	 for(int k=0;k<h;k++)
	 {
		for(int l=0;l<w;l++)
		{
		 if(elmh[k]==1||elmw[l]==1){if(c[k][l]=='#'){elm++;}}
		}
	 }
	 if((bc-elm)==kz){ans++;}
	}
}

printf("%d",ans);

}