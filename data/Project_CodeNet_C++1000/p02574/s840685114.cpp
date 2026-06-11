#include <bits/stdc++.h>
using namespace std;

const int M=1e6+5;
int a[M];

int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}

int isp[M],pri[M],pre[M],npri=0;
void get_pri()
{
    for(int i=2;i<M;i++)
    {
        if(!isp[i])
        {
            pre[i]=i;
            //pre[i]=npri;
            pri[npri++]=i;
        }
        for(int j=0;j<npri&&pri[j]*i<M;j++)
        {
            isp[i*pri[j]]=1;
            //pre[i*pri[j]]=j;
            pre[i*pri[j]]=pri[j];
            if(i%pri[j]==0) break;
        }
    }
}
vector<int> get_factor(int nu)
{
    vector<int> fa;
    if(nu==1) return fa; // fa.push_back(1);
    while(nu!=1)
    {
        fa.push_back(pre[nu]);
        nu/=pre[nu];
    }
    return fa;
}

int cnt[M],cnt2[M];

int main()
{
	get_pri();
	int n; scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);

	for(int i=0;i<n;i++)
	{
		vector<int> fas=get_factor(a[i]);
		for(int i:fas)
			cnt[i]++;
	}
	int f=1;
	for(int i=0;i<n;i++)
	{
		vector<int> fas=get_factor(a[i]);
		for(int i:fas)
			cnt2[i]++;
		for(int i:fas)
			if(cnt2[i]<cnt[i])
			{
				// cout<<i<<" "<<cnt[i]<<" "<<cnt2[i]<<endl;
				f=0;
				break;
			}
		if(f==0) break;
		for(int i:fas)
			cnt2[i]--;
	}
	if(f)
	{
		printf("pairwise coprime\n");
		return 0;
	}
	int g=a[0];
	for(int i=1;i<n;i++)
		g=gcd(g,a[i]);
	printf("%s\n",g==1 ? "setwise coprime" : "not coprime");
	return 0;
}