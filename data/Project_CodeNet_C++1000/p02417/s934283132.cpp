#include<stdio.h>
#include<string.h>
char a[2000];
long long int s[27],d,f,g,h,j,i;
int main(void)
{
	for(i=1;i<=26;i++)
			s[i]=0;
	while((scanf("%c",&a[1]))!=EOF){
		//d=strlen(a);
	/*	for(i=0;i<=d+1;i++)
			printf("%c\n",a[i]);*/
		//for(i=0;i<=d;i++){
			if(a[1]>=65&&a[1]<=90)
				a[1]+=32;
		//}
		//for(i=0;i<d;i++){
			for(j=1;j<=26;j++){
			//	printf("    %d %c %d\n",a[i]-'0',a[i],a[i]-'0'-48);
				if(j==a[1]-'0'-48){
					s[j]++;
				//	printf("%d %d\n",s[j],j);
				}
			}
		}
	printf("a : %d\n",s[1]);
	printf("b : %d\n",s[2]);
	printf("c : %d\n",s[3]);
	printf("d : %d\n",s[4]);
	printf("e : %d\n",s[5]);
	printf("f : %d\n",s[6]);
	printf("g : %d\n",s[7]);
	printf("h : %d\n",s[8]);
	printf("i : %d\n",s[9]);
	printf("j : %d\n",s[10]);
	printf("k : %d\n",s[11]);
	printf("l : %d\n",s[12]);
	printf("m : %d\n",s[13]);
	printf("n : %d\n",s[14]);
	printf("o : %d\n",s[15]);
	printf("p : %d\n",s[16]);
	printf("q : %d\n",s[17]);
	printf("r : %d\n",s[18]);
	printf("s : %d\n",s[19]);
	printf("t : %d\n",s[20]);
	printf("u : %d\n",s[21]);
	printf("v : %d\n",s[22]);
	printf("w : %d\n",s[23]);
	printf("x : %d\n",s[24]);
	printf("y : %d\n",s[25]);
	printf("z : %d\n",s[26]);
	return 0;
}