#include <iostream>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define ll long long
int main(int argc, char** argv) {
	string s;
	cin>>s;
	int ans=0;
	int lst=0;
	char ls='?';//3  2  2   1 
	rep(i,0,s.length()-1)
	{
		int j=i;
		while(s[j]==s[i])
		{
			j++;
		}
		if((j-i-lst)%3<=1)
		{
			ans+=(j-i-lst)/3;
		
			//cout<<(j-i-lst)<<"?"<<endl;
			lst=0;
		}
		else
		{
			
			ans+=(j-i-lst)/3+1;
		//	if((j-i-lst)/3+1)
			//cout<<(j-i-lst)<<endl;
			//cout<<j<<" "<<i<<endl;
			lst=1;
		}
		i=j-1;
	}
	ans=s.length()-ans;
	cout<<ans;
	return 0;
}