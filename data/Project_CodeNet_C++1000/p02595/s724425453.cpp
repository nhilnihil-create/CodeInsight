#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
  	double d;
  	cin >> n >> d;
  	int cnt = 0;
  	int x,y;
  	for(int i=0;i<n;i++){
    	cin >> x >> y;
      	if(sqrt(pow(x,2) + pow(y,2)) <= d){
        	cnt++;
        }
    }
  	cout << cnt << endl;
}