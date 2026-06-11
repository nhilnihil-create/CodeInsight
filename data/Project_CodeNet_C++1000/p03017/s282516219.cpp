#include <iostream>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define rep(i,a,b) for(int i=a;i<=b;i++)
int fg[200005],fg2[200005];
int main(int argc, char** argv) {
	int n,a,b,c,d;
	cin>>n>>a>>b>>c>>d;
	
	string s;
	cin>>s;
	if(c==d){
	printf("No");return 0;}
	fg[b-1]=1,fg2[a-1]=1;
	rep(i,b,d-1)
	{
		if((fg[i-1]||fg[i-2])&&s[i]=='.')
		{
			fg[i]=1;
		}
	}
	
	rep(i,a,c-1)
	{
		if((fg2[i-1]||fg2[i-2])&&s[i]=='.')
		{
			fg2[i]=1;
		}
	}
	
	if(!fg[d-1]||!fg2[c-1])
	{
		printf("No");
		return 0;
	}
	
	if(d<c)
	{
		rep(i,b-2,d-1)
		{
			int j=i;
			if(s[i]!='.')continue;
			while(s[j]==s[i]&&j<=d)j++;
			if(j-i>=3)
			{
				printf("Yes");
				return 0;
			}
			i=j-1;
		}
		printf("No");
	}
	else printf("Yes"); 
	
	
	return 0;
}