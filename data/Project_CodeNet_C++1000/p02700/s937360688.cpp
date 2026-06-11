#include<bits/stdc++.h>
using namespace std;


int main(){
	int a, b, c, d;
  cin>>a>>b>>c>>d;

	int cnt1 = 0, cnt2 = 0;

	while(a > 0){
		a = a - d;
		cnt2++;
	}

  // cout<<"a => "<<a<<"cnt1 "<<cnt1<<"\n";

	while(c > 0){
		c = c - b;
		cnt1++;
	}

  // cout<<"c => "<<c<<"cnt2 "<<cnt2<<"\n";

	if(cnt1<= cnt2){
		cout<<"Yes\n";
	}
	else{
		cout<<"No\n";
	}


	return 0;
}