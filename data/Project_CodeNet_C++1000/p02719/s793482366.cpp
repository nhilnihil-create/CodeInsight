#include<bits/stdc++.h>
using namespace std;
 
int main(){
  long long a,b;
  cin>>a>>b;
  if(a>=b){
  	long long r = a%b;
  	long long mindist = r;
  	mindist = min(r,b-r);
  	cout<<mindist;
  }
  else{
  	long long mindist = b-a;
  	a = mindist; 
  	mindist = min(mindist,b-a);
  	cout<<mindist;
  }
}