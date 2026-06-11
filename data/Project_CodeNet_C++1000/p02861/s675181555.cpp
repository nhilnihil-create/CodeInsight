#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	
  	double ans = 0;
	int n,a,b;
  	cin >> n;
  	int p=1;
 	for(int i=1;i<=n;i++) p*=i;
  
  	vector<pair<int,int > > data;
	vector<int> v;
  	for(int i=1;i<=n;i++) v.push_back(i);
 	for(int i=0;i<n;i++) {
    	cin >> a >> b;
      	data.push_back(make_pair(a,b));
 	}
  	int c = 1;
  
  	do {
    	for(int i=1;i<n;i++) {
        	int x = data[v[i-1]-1].first  - data[v[i]-1].first;
          	int y = data[v[i-1]-1].second - data[v[i]-1].second;
          
          	ans += sqrt(x*x + y*y);
        }
      	//cout << c << endl;
        //c++;
    } while(next_permutation(v.begin(), v.end()));
  
  	printf("%f", ans/p);
}