#include<bits/stdc++.h>
#define mod 1000000009
#define int long long
#define garou ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
int pow(int p,int r){
	int ans=1;
	while(r>0){
     if(r&1){
		 ans=((ans%mod)*(p%mod))%mod;
	 }
	 r=r>>1;
     p=((p%mod)*(p%mod))%mod;
	}
	return ans;
}
signed main() {
	 garou;
	 int k;
     cin>>k;
     queue<int> q;
     vector<int> v;
     for(int i=1;i<=9;i++){
         q.push(i);
         v.push_back(i);
     }
     while(q.front()<=3234566667){
     int a=q.front();
     q.pop();
  if(a%10!=0){
      int b=a*10+(a%10)-1;
      v.push_back(b);
      q.push(b);
  }
  int b=a*10+(a%10);
  v.push_back(b);
  q.push(b);
  if(a%10!=9){
      int b=a*10+(a%10)+1;
      v.push_back(b);
      q.push(b);
  }
     }
     cout<<v[k-1];
}