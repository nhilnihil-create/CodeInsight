#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,res=0;
  	cin >> n;
  	for(int i=1;i<=n;i++){
    	string a=to_string(i);
      	if(a.size() % 2 !=0) res++;
    }
  	cout << res << endl;
}