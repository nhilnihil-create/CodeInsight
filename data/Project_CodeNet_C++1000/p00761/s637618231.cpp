#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int a,l;
main()
{
	while(cin>>a>>l,l)
	{
		map<int,int>m;
		m[a]=1;
		for(int i=2;;i++)
		{
			int cnt[10]={};
			int p=10;
			for(int j=0;j<l;j++,p*=10)
			{
				cnt[a%p/(p/10)]++;
			}
			int maxa=0,mina=0;
			for(int i=9;i>=0;i--)
			{
				int nowcnt=0;
				while(cnt[i]>nowcnt)maxa=maxa*10+i,nowcnt++;
			}
			for(int i=0;i<10;i++)
			{
				int nowcnt=0;
				while(cnt[i]>nowcnt)mina=mina*10+i,nowcnt++;
			}
			a=maxa-mina;
			if(m[a])
			{
				cout<<m[a]-1<<" "<<a<<" "<<i-m[a]<<endl;
				break;
			}
			m[a]=i;
		}
	}
}
