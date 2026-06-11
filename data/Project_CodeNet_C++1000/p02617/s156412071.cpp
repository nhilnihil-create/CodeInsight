#include<bits/stdc++.h>
using namespace std;
#define asll unsigned long long
#define ll long long //20190711
#define pii pair<int,int>
#define st first
#define nd second
#define jn <<" "<< 			//20190830
#define ml <<endl; 			//20190831->20190903
#define co cout<<           //20190903


asll M=1e9+7;				//20190518->20190821
int n;						//20190831

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	srand(time(0));			//20190709
	
	
	cin>>n;
	int a,b,c,d;
	asll jml=((asll)n)*((asll)n+2)*((asll)n+1)/6;
	//cout<<jml<<endl;
	for(int i=0;i<n-1;i++){
		cin>>a>>b;
		c=min(a,b);
		d=max(a,b);
		jml-=(asll)(n-d+1)*(asll)c;
		//cout<<(n-d+1)*c ml
	}
	cout<<jml<<endl;
	
}

