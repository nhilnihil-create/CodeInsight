#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<=(n);i++)
typedef long long ll;

int main() {
	int n,m;
  	cin>>n>>m;
  
  int WA[105000];

  bool ch[105000];
  
  int num;
  string res;
  int ans=0;
  int wrong=0;

  
  rep(i,n){
    WA[i]=0;
    ch[i]=false;
  }
  rep(j,m){
  cin>>num>>res;
    

    if(ch[num]==false&&res=="WA"){
    	WA[num]++;
    }
    else if(ch[num]==false&&res=="AC"){
 
    	ans++;
      	ch[num]=true;
      	wrong+=WA[num];
    }

    
  }
               
    cout<<ans<<" "<<wrong<<endl;

  	
}