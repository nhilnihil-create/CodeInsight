#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int n,m;
  	cin >> n >> m;
  	vector<int> a(n);
  	double sum = 0;
  	for(int i=0;i<n;i++){
    	cin >> a.at(i);
      	sum += a.at(i);
    }
  	double min = sum / (4*m);
  	sort(a.begin(),a.end());
  	reverse(a.begin(),a.end());
  	bool e = true;
  	for(int i=0;i<m;i++){
    	if(a.at(i) < min){
        	e = false;
          	break;
        }
    }
      if(e==true) cout << "Yes" << endl;
      else cout << "No" << endl;
 
    
}