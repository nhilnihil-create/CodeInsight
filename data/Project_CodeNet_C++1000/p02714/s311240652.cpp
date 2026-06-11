#include <bits/stdc++.h>
using namespace std;
char remain(char x,char y){
	if(x!='R'&&y!='R') return 'R';
    if(x!='G'&&y!='G') return 'G';
    if(x!='B'&&y!='B') return 'B';
}
int main() {
   int n;
   cin>>n;
   string s;
   cin>>s;
   vector<long long> r(n+1,0),g(n+1,0),b(n+1,0);
   r[0]=0,g[0]=0,b[0]=0;
   for(int i=0;i<n;i++){
   	if(s[i]=='R'){
    	r[i+1]=r[i]+1;
        g[i+1]=g[i];
        b[i+1]=b[i];
    }else if(s[i]=='G'){
    	g[i+1]=g[i]+1;
        r[i+1]=r[i];
        b[i+1]=b[i];
    }else if(s[i]=='B'){
    	b[i+1]=b[i]+1;
        g[i+1]=g[i];
        r[i+1]=r[i];
    }
   }
  long long ans=0;
   for(int i=0;i<n-2;i++){
   	for(int j=i+1;j<n-1;j++){
    	if(s[i]!=s[j]){
        	char x=remain(s[i],s[j]);
            if(x=='R') ans+=r[n]-r[j+1];
            else if(x=='G') ans+=g[n]-g[j+1];
            else if(x=='B') ans+=b[n]-b[j+1];
            if(2*j-i<n&&s[2*j-i]==x) ans--;
        }
    }
   }
   cout<<ans;
}
