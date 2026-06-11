 #include<bits/stdc++.h>
/* 
*    coder :: ATUL_PANDEY_2608
*        >>> INDIA <<<
*/
using namespace std;

// #define  part ..
#define listi vector<int > 
#define listll vector<long long >
#define pii pair<int ,int > 
#define pll pair<long long ,long long >
#define heap priority_queue<long long >

#define pb(a) push_back(a)
#define mod 1000000007
#define maxx 200006
#define ll long long 
#define quick  	ios_base::sync_with_stdio(NULL),cin.tie(0);
#define rep(i,a,b) for(int i=a;i<b;i++)
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// #define test int t;cin>>t;while(t--)
// end of #define 

// define globals ...









//write function from here ...









int Main(){


string s;
cin>>s;
int n= s.length();
if(s[0]=='?'){
	if(1>n &&(s[1] =='D'||s[1]=='?'))
	{
		s[0]='P';
	}
	else{
		s[0]='D';
	}
}

for(int i=1;i<n;i++){
	if(s[i]=='?'){
		if(s[i-1]=='P'){
		s[i]='D';
		}
		else if( i+1<n && s[i+1]=='D')
		{
			s[i]='P';
		}
		else
			s[i]='D';

	}
}



cout<<s;


return 0;



}
























// main function..
int main(){
	quick;  
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    Main();
    
    
}
