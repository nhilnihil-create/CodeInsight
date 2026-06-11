#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n;
  	cin>>n;
  	vector<string> v;
  	for(int i=0;i<n;i++){
    	string s;
      	cin>>s;
      	v.push_back(s);
    }
  	sort(v.begin(), v.end());
  	
  	long long int cnt=1;
  	for(int i=1;i<n;i++){
    	if(v[i-1]!=v[i]){
        	cnt++;
        }
    }
  	cout<<cnt<<endl;
}