#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
/*int main()
{
	int n; cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
//	for(int i=0;i<n;i++) cout<<a[i];
	int sum=0;
	for(int i=n-1;i>1;i--)
	{
		for(int j=i-1;j>0;j--)
		{
			if(a[i]==a[j]) continue;
			for(int k=j-1;k>=0;k--)
			{
				if(a[k]!=a[i] and a[k]!=a[j] and a[i] < (a[k] + a[j])) 
				{
					sum++;
				}
				
				if(a[k]!=a[i] and a[k]!=a[j] and a[i] >= (a[k] + a[j])) 
				{
					break;
				}
				
			}
		}
	}
	
	cout<<sum;
}

int main()
{
	int n,d,ans=0;
	cin>>n>>d;
	while(n--)
	{
		int a,b; cin>>a>>b;
		long long int fl=a*a + b*b;
		float sum=sqrt(fl);
		if(sum<=d) ans++;
		
	}
	cout<<ans;
}
int main()
{
	int n,k; cin>>n>>k;
	int a[n],sum=0;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<k;i++) sum+=a[i];
	cout<<sum; 
}

int main()
{
	int n,k; cin>>n>>k;
	k%2==0 and k>=2*n and k<=4*n ? cout<<"Yes" : cout<<"No";
}

int main()
{
	int n; cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	unsigned long long ans=1,ANS;
	vector<int>v;
	for(int i=0;i<n;i++)
	{
		ans*=a[i];
		ANS=ans;
		while(ANS)
		{
			v.push_back(ANS%10);
			ANS/=10;
		}
		if(v.size()>1000000000000000000)
		{
			cout<<"HRE";
			cout<<"-1";
			return 0;
		}
		v.clear();
	}
	cout<<ans;
}

int main()
{
	int n; cin>>n;
	string s; cin>>s;
	if(s.size()<=n) cout<<s;
	else {
		
	for(int i=0;i<n;i++) cout<<s[i];
	cout<<"...";
}}

int main()
{
	long long int a,b,c,d; cin>>a>>b>>c>>d;
	long long int sum=0,count=0;
	if(a<=d)
	{
		sum+=a;
		d-=a;
		if(d==0)
		{
			cout<<sum;
			return 0;
		}
	}
	else 
	{
		cout<<d;
		return 0;
	}
	
		if(b<=d)
	{
		
		d-=b;
		if(d==0)
		{
			cout<<sum;
			return 0;
		}
	}
	else 
	{
		cout<<d;
		return 0;
	}
	
		if(c<=d)
	{
		sum-=c;
		d-=c;
		if(d==0)
		{
			cout<<sum;
			return 0;
		}
	}
	else 
	{
		cout<<sum-d;
		return 0;
	}
	
	
}


int main()
{
	int n,k; cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++) a[i]=0;
	while(k--)
	{
		int d; cin>>d;
		for(int i=0;i<d;i++) 
		{
			int x; cin>>x;
			a[x-1]++;
		}
	}
	//cout<<a[2];
	int ans=0;
	for(int i=0;i<n;i++) if(a[i]==0) ans++; cout<<ans;
}
int main()
{
	long long int n,year=0; cin>>n;
	int a=100;
	while(a<n)
	{
		float aa=(1.0/100)*a;
		a+=floor(aa);
		year++;
	}
	cout<<year;
}
int main()
{
	long long int n,m; cin>>n>>m;
	long long int sum=0,a[n];
	for(long long int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];	
	} 
	sort(a,a+n,greater<int>());
	float min=sum*1.0/(4*m);
	a[m-1]<min?cout<<"No": cout<<"Yes\n";	
}

int main()
{
	int n; cin>>n;
	long long sum=(n/500)*1000 + ((n-(n/500)*500)/5)*5;
	cout<<sum;
}

int main()
{
	string s; cin>>s;
	
	if(s.size()%2==0) 
	{
		cout<<"No";
		return 0;
	}
	
	if(s.size()==3) 
	{
		cout<<"Yes";
		return 0;
	}
	int si=s.size()/2;
	for(int i=0;i<si/2;i++)
	{
		if(s[i]!=s[si-i-1]) 
		{
			cout<<"No";
			return 0; 
		}
	}
	int aa=s.size();
	for(int i=si+1;i<si+si/2+1;i++)
	{
		if(s[i]!=s[aa-1]) 
		{
			cout<<"No";
			return 0;
		}
		aa--;
	}
	
	cout<<"Yes";
}


int main()
{
	long long int n,a,b; cin>>n>>a>>b;
	long long int sum=n/(a+b)*a;
	n=n%(a+b);
	if(n<=a) sum+=n;
	else sum+=a;
	cout<<sum;
}
int main()
{
	int a[3][3];
	for(int i=0;i<3;i++) for(int j=0;j<3;j++) cin>>a[i][j];
	int n; cin>>n;
	
	for(int i=0;i<n;i++)
	{
		int b;
		cin>>b;
		for(int i=0;i<3;i++) for(int j=0;j<3;j++) if(a[i][j]==b) a[i][j]=0;
	} 
	bool u=false;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(a[i][j]!=0) break;
			if(j==2) u=true;
		}
	}
	
	if(u) 
	{
		cout<<"Yes";
		return 0;
	}
	
	for(int j=0;j<3;j++)
	{
		for(int i=0;i<3;i++)
		{
			if(a[i][j]!=0) break;
			if(i==2) u=true;
		}
	}
	
	if(u) 
	{
		cout<<"Yes";
		return 0;
	}
	
	if(a[2][0] == 0 and a[1][1] == 0 and a[0][2] == 0) 
	{
		cout<<"Yes";
		return 0;
	}
	
		if(a[0][0] == 0 and a[1][1] == 0 and a[2][2] == 0) 
	{
		cout<<"Yes";
		return 0;
	}
	
	cout<<"No";
}
int main()
{
	int a,b,B,sum=1; cin>>a>>b;
	B=b;
	while(b<=a)
	{
		b*=B;
		sum++;
	}
	
	cout<<sum;
}


/*		if(a[0][0] == 0 and a[1][1] == 0 and a[2][2] == 0) 
	{
		cout<<"Yes";
		return 0;

		
		
int main()
{
	int n; cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++)
	{
		if(a[i]&1) continue;
		if(a[i]%3!=0 and a[i]%5!=0) 
		{
		//	cout<<a[i]<<" "<<a[i]%3<<"\n";
			cout<<"DENIED"; return 0;
		}
	}
	
	cout<<"APPROVED";
}

int main()
{
	string s; cin>>s;
	for(int i=0;s[i];i++) cout<<"x";	
}*/

int main()
{
	int a,n,sum=0; cin>>a>>n;
	int aa[n];
	for(int i=0;i<n;i++) {
	cin>>aa[i];
	sum+=aa[i];
	}
	sum>=a?cout<<"Yes": cout<<"No";
		
}	
