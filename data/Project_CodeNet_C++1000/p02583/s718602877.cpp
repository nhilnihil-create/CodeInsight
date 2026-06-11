#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,temp,count=0;
	cin>>n;
	vector<int> a;
	for(int i=0;i<n;i++){
	    cin>>temp;
	    a.push_back(temp);
	}
	sort(a.begin(),a.end());
	for(int i=0;i<a.size();i++){
	    for(int j=i+1;j<a.size();j++){
	        for(int k=j+1;k<a.size();k++){
	            
	            if(a[i]!=a[j]&& a[j]!=a[k]){
	                
	            if(a[i]+a[k]>a[j] && a[i]+a[j]>a[k] && a[j]+a[k]>a[i]){
	                
	                
	                count++;
	            }
	        }
	    }
	}
	}
	cout<<count;
	return 0;
}
