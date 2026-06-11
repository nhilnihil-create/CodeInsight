#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>
#include<iomanip>
#include<sstream>
#include<vector>
#include<stack>
#include<math.h>
#include<queue>
#include<complex>
#include<random>
#include<ctime>
#include<set>
using namespace std;


const long long int mod=1000000007;
const long long int INF=99999999999999999;


long long int n;
char ch[1004];
map<char,long long int>mp;

long long int solve(string s){
	long long int ret=0;
	for(int i=0;i<s.length();i++){
		if(s[i]<='9'&&s[i]>='2'){ret+=(s[i]-'0')*mp[s[i+1]];i++;}
		else{ret+=mp[s[i]];}
	}
	return ret;
}

void cou(long long int num,long long int ccc){
	if(num==0){return;}
	else if(num==1){cout<<ch[ccc];return;}
	else {cout<<num<<ch[ccc];return;}
}

int main() {
	string s,t;
	mp['m']=1000;
	mp['c']=100;
	mp['x']=10;
	mp['i']=1;
	ch[1]='i';
	ch[2]='x';
	ch[3]='c';
	ch[4]='m';
	cout << fixed << setprecision(18);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s>>t;
		long long int res=solve(s)+solve(t);
		long long int m=res/1000,c=res/100%10,x=res/10%10,ii=res%10;
		//cout<<"DEBUG "<<solve(s)<<" "<<solve(t)<<endl;
		cou(m,4);cou(c,3);cou(x,2);cou(ii,1);
		cout<<endl;
	}

} 
