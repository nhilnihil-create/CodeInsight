#include <bits/stdc++.h>
#define cinf(n,x) for(int i=0;i<(n);i++) cin >> x[i];
typedef long long int ll;
using namespace std;

int main(){
	while(1){
	  int h,w; cin >> h >>w;
	  if(h==0 && w==0)break;
	  for(int i=0;i<h;i++){
	  	if(i==0 || i==h-1){
	  		for(int j=0;j<w;j++){
	  			cout <<"#";
	  		}
	  		cout << endl;
	  	}
	  	else{
	  		cout << "#";
	  		for(int j=1;j<w-1;j++){
	  			cout << ".";
	  		}
	  		cout << "#";
	  		cout << endl;
	  	}
	  }
	  cout << endl;
    }
}

