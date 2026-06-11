#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>


#define rep(i,n) for(i=0;i<n;i++)

using namespace std;




int main(){
	
	string s;
	
	int q[111];
	int qn;
	int i;
	bool f;
	
	fill(q,q+110,0);qn=0;
	f=true;
	
	
	while(true){
		//scanf("%s",s);
		
		getline(cin,s);
		
		if(s[0]=='.'&&s[1]==0)break;
		
		

		
		for(i=0;s[i]!=0;i++){
			if(f && s[i]=='('){
				q[qn++]=1;
			}
			if(f && s[i]=='['){
				q[qn++]=2;
			}
			if(f && s[i]==')'){
				if(qn==0){f=false;}
				if(q[--qn]!=1){f=false;}
			}
			if(f && s[i]==']'){
				if(qn==0){f=false;}
				if(q[--qn]!=2){f=false;}
			}
			if(s[i]=='.'){
				if(f && qn==0)puts("yes");
				else puts("no");
				
				fill(q,q+110,0);qn=0;
				f=true;
				
				break;
			}
		}
		
	
	}
	
	
}