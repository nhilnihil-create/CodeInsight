#include<iostream>
#include <vector>
#include <cstdlib>
using namespace std;
int main()
{
    long long k,n;
    cin >> k >> n;
	
  	vector<long long> a;
    long long d,dis=0;
    cin >> d;
    a.push_back(d);
  	for(int i=1;i<n;i++){
      cin >> d;
      a.push_back(d);
     if(dis<a[i]-a[i-1])  dis = a[i]-a[i-1]; 
     if(i==n-1 && dis<k-a[n-1]+a[0])  dis = k-a[n-1]+a[0];
    }
    cout << k-dis << endl;
    return 0;
}