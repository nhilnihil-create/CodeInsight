#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;
int main(){
int n,m;
cin >> n >> m;
int a[m];
for(int i = 0;i < m;i++){
	cin >> a[i];
	}
int s = accumulate(a,a+m,0);
if(n < s){
	cout << "-1" << '\n';
	}
else{
	cout << n - s << '\n';
	}
return 0;
}