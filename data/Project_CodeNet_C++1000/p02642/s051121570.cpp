#include <bits/stdc++.h>
using namespace std;
int main(){
	vector<int> seive(2000001);
  	long int n,k;
  	cin >> n;
  	for(int i=0;i<n;i++){
    	cin >> k;
      	seive[k]++;
    }
  	long int not_divisible=0;
  	vector<int> divisible(2000001,0);
  	for(int i=1;i<=2000000;i++){
    	if(seive[i]==0 || divisible[i])
          	continue;
      	if(seive[i]==1 && !divisible[i])
          	not_divisible++;
		for(int j=i;j<2000000;j+=i)
          	divisible[j]=1;
    }
  cout << not_divisible;
  return 0;
}
