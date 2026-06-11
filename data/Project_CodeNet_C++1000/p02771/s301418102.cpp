#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;
int main(){
int l,n,m;
cin >> l >> n >> m;
if(n == m && n == l){
  cout << "No" << '\n';
	}
else if(n == m || n == l || l == m){
  cout << "Yes" << '\n';
	}
else{
  cout << "No" << '\n';
	}
return 0;
}