	#include<bits/stdc++.h>
	using namespace std;
	#define xxx ios::sync_with_stdio(),cin.tie(0),cout.tie(0)
	#define rep(i,n) for(int i=0;i<n;i++)
	#define repeq(i,j,n) for(int i=j;i<n;i++)
	#define int long long
	int bp(int a, int b, int m) {
   		a %= m;
   		int res = 1;
    	while (b > 0) {
        	if (b & 1)
            	res = res * a % m;
       		a = a * a % m;
       	 	b >>= 1;
 	    }
    return res;
	}
	int max(int a, int b){
		return (a>b)?a:b;	
	}
	int csb( int n) 
{ 
    int count = 0; 
    while (n) { 
        count += n & 1; 
        n >>= 1; 
    } 
    return count; 
} 
	int solve(int x){
		int r=0;
		while(x>0){
			int t=csb(x);
			x%=t;
			r++;
		}
		return r;
	}
	string mkstr(int n,char c){
		string s;
		s+=c;
		if(n==1 || n==0) return s;
		string s1,s2;
		s1=mkstr(n/2,c);
		s2=mkstr(n/2,c);
		return s1+s2;
	}
	int fun(string s,int n,char c){
		if(n==1){
			if(s[0]==c) return 0;
			else return 1;
		}
		else if(n==0) return 0;
		string s1=s.substr(0,n/2);
		string s2=s.substr(n/2,n);
		int ans1=0,ans2=0;
		for(int i=0;i<n/2;i++){
			if(s1[i]!=c) ans1++;
			if(s2[i]!=c) ans2++;
		}
		ans1+=fun(s2,n/2,c+1);
		ans2+=fun(s1,n/2,c+1);
		return min(ans1,ans2);

	}
	// void dfs(int v,vector<int> visited,vector<vector<int>> adjd,vector<vector<int>> adjud) {
    	
 //    	visited[v] = 1;
 //    	for (int u : adjd[v]){
 //        	if (color[u] == 0){
 //        	    dfs(u);
 //        	}
 //    	}
    	

 //   	 	visited[v] = 2;
    	
	// }
	signed main(){
		int test=1;
		//cin>>test;
		while(test--){
			string s;
			cin>>s;
			string a="Sunny",b="Cloudy",c="Rainy";
			if(s[0]=='S') cout<<b<<endl;
			if(s[0]=='C') cout<<c<<endl;	
			if(s[0]=='R') cout<<a<<endl;

		}
		return 0;
	}