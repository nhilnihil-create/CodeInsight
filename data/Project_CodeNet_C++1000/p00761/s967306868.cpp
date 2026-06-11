#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  while(cin>>n>>m){
    if(n==0&&m==0){break;}
    int x=n;
  	int a[30],b[30];
    a[0]=n;
    vector<int>v;
    while(x!=0){
      v.push_back(x%10);
      x/=10;
    }
    int g=m-v.size();
	while(g--){
      v.push_back(0);
    }
    sort(v.begin(),v.end());
    int k=1;
    while(k){
      	int x=0,y=0;
    	for(int i=0; i<v.size(); i++){
      		x+=v[i]*pow(10,v.size()-i-1);
      		y+=v[v.size()-1-i]*pow(10,v.size()-i-1);
    	}
      	a[k]=max(x,y)-min(x,y);
        b[k]=a[k];
      	for(int i=0; i<v.size(); i++){
          v[i]=b[k]%10;
          b[k]/=10;
        }
      	sort(v.begin(),v.end());
      	k++;
      	if(k>20){break;}
    }
	    vector<pair<int,int>>vec;
    for(int i=0; i<50; i++){
      for(int j=0; j<50; j++){
        	if(i<=j){continue;}
        	if(a[i]==a[j]){
              vec.push_back(make_pair(i,j));
            }  
      	}
    }
    sort(vec.begin(),vec.end());
    cout<<vec[0].second<<" "<<a[vec[0].first]<<" "<<vec[0].first-vec[0].second<<endl;
  }
}
    
    
    
      
  
  
