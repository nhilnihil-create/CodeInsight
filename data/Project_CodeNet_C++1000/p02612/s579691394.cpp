#include <bits/stdc++.h>

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false); 
 
    cin.tie(NULL);
 
    cin.tie(NULL);
  	int n;
  	cin>>n;
  	int q=(n/1000);
  	if(n%1000){q++;}
  	q=q*1000-n;
  	cout<<q<<"\n";
  return 0;
}