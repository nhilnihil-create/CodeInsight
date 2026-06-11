#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int INF=1<<29,MOD=1e9+7;

int main(){
	int day=24*3600+60*60+60;
	int n;
	while(cin>>n&&n){
		int a[day]={};
		for(int i=0;i<2*n;i++){
			int time;
			string s; cin>>s;
			time=(s[0]-'0')*36000+(s[1]-'0')*3600+(s[3]-'0')*600+(s[4]-'0')*60+(s[6]-'0')*10+(s[7]-'0');
			if(i%2==0) a[time]++;
			else a[time]--;
		}
		for(int i=1;i<day;i++){
			a[i]=a[i]+a[i-1];
		}
		sort(a,a+day); reverse(a,a+day);
		cout<<a[0]<<endl;
	}
	return 0;
}

