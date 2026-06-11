#include<bits/stdc++.h>
#define MAX 300005
 
using namespace std;
int use[MAX];
vector<int> a;
int main(){
  int n,x;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>x;
    use[x]++;
  }
  int cnt = 0;
  for(int i=1;i<=n;i++){
    	if(use[i])a.push_back(use[i]);
  }
  sort(a.begin(),a.end());
  int sum = n;
  for(int i=1;i<=n;i++){
    	while(a.back() > sum/i){
        	int len = a.size();
            int dup = 0;
            while(len && a[len-1] > sum/i){
            	--a[--len];
              	  dup++;
            }
            sum -= dup;
        }
    	cout<<sum/i<<endl;
  }
  return 0; 
}