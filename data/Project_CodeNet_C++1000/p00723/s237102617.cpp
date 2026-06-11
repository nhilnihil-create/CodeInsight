#include <iostream>
#include <string>
#include <map>
using namespace std;

main(){
  int n;
  while(cin >> n){
    int ans;
    string in;
    for(int i=0;i<n;i++){
      map<string,bool> data;
      cin >> in;
      ans=0;
      for(int j=1;j<in.size();j++){
	string a="", b="";
	int tmp;
	for(int k=0;;k++){
	  if(k==j){
	    tmp=k;
	    break;
	  }
	  a+=in[k];
	}
	for(int k=tmp;k<in.size();k++){
	  b+=in[k];
	}
	
	string t;
	t=a+b;
	if(!data[t]){
	  data[t]=true;
	  ans++;
	}
	t=b+a;
	if(!data[t]){
	  data[t]=true;
	  ans++;
	}
	string c="";
	for(int k=a.size()-1;k>=0;k--){
	  c+=a[k];
	}
	t=c+b;
	if(!data[t]){
	  data[t]=true;
	  ans++;
	}
	t=b+c;
	if(!data[t]){
	  data[t]=true;
	  ans++;
	}
	string d="";
	for(int k=b.size()-1;k>=0;k--){
	  d+=b[k];
	}
	t=a+d;
	if(!data[t]){
	  data[t]=true;
	  ans++;
	}
	t=d+a;
	if(!data[t]){
	  data[t]=true;
	  ans++;
	}
	t=c+d;
	if(!data[t]){
	  data[t]=true;
	  ans++;
	}
	t=d+c;
	if(!data[t]){
	  data[t]=true;
	  ans++;
	}
      }
      cout << ans << endl;
    }
  }
  return 0;
}

  