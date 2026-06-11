#include <iostream>
#include <vector>
using namespace std;


int main(){
	int n, m, q;
  	cin>>n>>m>>q;
  	int a[q], b[q], c[q], d[q];
  	for(int i=0;i<q;i++){
    	cin>>a[i]>>b[i]>>c[i]>>d[i];
    }
  
  	vector<pair<int, pair<int, int>> > v;
  	for(int i=1;i<=m;i++){
  		v.push_back(make_pair(-1, make_pair(0, i)));
    }
  	int bn=0;
  	int num=0;
  	while(1){
      	if(num==v[bn].second.first) num++;
      	if(num==n) break;
    	for(int i=v[bn].second.second;i<=m;i++){
  			v.push_back(make_pair(bn, make_pair(num, i)));
    	}
      	bn++;
    }
  	
  	int max=-1;
  	int sum=0;
  	for(int i=v.size()-1;v[i].second.first==n-1;i--){
    	int t[n];
      	int l=n-1;
      	for(int j=i;;j=v[j].first){
      		t[l]=v[j].second.second;
          	l--;
          	if(v[j].first==-1) break;
        }
      	//if(t[0]==1 && t[1]==3 && t[2]==4) cout<<"ok"<<endl;
      
      	for(int k=0;k<q;k++){
        	if(t[b[k]-1]-t[a[k]-1]==c[k]) sum+=d[k]; 
        }
      	if(max<sum) max=sum;
      	sum=0;
    }
  	
  	cout<<max<<endl;
  	
  	for(int i=0;i<v.size();i++){
  		//cout<<v[i].second.first<<endl;
    }
}