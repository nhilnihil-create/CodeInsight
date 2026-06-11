//RRLRRLLRL
//focus only on rl intersections
//everything will end up there
//for every r - l intersection I have the count
#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int main(){
	 cin>>s;
  	 n = s.size();
  vector<int >nosr;
  vector<int >nosl;
  vector<int >fin(n,0);
  int curr=0;
  //cout<<s<<'\n';
  	for(int i=0;i<s.size();i++){
      	if(s[i]=='L')continue;
    	if(s[i]=='R' && s[i+1]!='L')curr++;
      else {curr++;nosr.push_back(curr);curr=0;}
    }

  curr=0;
    	for(int i=s.size()-1;i>=0;i--){
      	if(s[i]=='R')continue;
    	if(s[i]=='L' && s[i-1]!='R')curr++;
      else {curr++;nosl.push_back(curr);curr=0;}
    }

  reverse(nosl.begin(),nosl.end());
 // cout<<nosr.size()<<' '<<nosl.size()<<'\n';
  int j=0;
  
  for(int i=0;i<n ;i++){
  	if((s[i]=='R' && s[i+1]=='L')){
      fin[i]=ceil(nosr[j]/2.0)+floor(nosl[j]/2.0);
      fin[i+1]=ceil(nosl[j]/2.0)+floor(nosr[j]/2.0);
      j+=1;
      i+=1;
    }
  }
  for(int i=0;i<n;i++)cout<<fin[i]<<' ';
  //rrrlll
  
}