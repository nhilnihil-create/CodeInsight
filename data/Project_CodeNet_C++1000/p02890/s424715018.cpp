#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> freq(n+5);
  //memset(freq,0,sizeof(freq));
  int a1;
  for(int i=0;i<n;i++){
    cin>>a1;
    freq[a1]+=1;
  }
  vector<int> c,f1;
  for(int i=0;i<=n;i++){
	  if(freq[i])
	    c.push_back(freq[i]);
	}
  sort(c.begin(),c.end());
  //vector<int> f1(n+5);
  //memset(f1,0,sizeof(f1));
  //f1[0]=freq[0];
  f1.push_back(c.front());
  for(int i=1;i<c.size();i++)
    f1.push_back(f1.back()+c[i]);
   //cout<<n<<endl; 
  for(int i=1;i<=n;i++){
    int l=0,u=n/i;
    int m;
    while(l!=u){
      m=(l+u)/2+1;	
      int i1=lower_bound(c.begin(),c.end(),m)-c.begin();
      int t1=c.size()-i1;
      if(i1>0)
        t1+=f1[i1-1]/m;
      if(t1>=i)
        l=m;
      else
        u=m-1;
    }
    cout<<l<<endl;
  }
}
             
