#include <bits/stdc++.h>

using namespace std;

int ans = 0;

int mod(int num, int k){
	int re;
	int a;
	a = num / k;
	re = num - k * a;
	return re;
}
void func(int num,int k){
	if(num % k == 0){
		ans++;
	}
	else if(ans < k * 2){
		num = mod(num,k);
		num = num * 10 + 7;
		ans++;
		
		//cout<<num<<endl;
		func(num,k);
	}
}
int main(void){
	int k;
	cin>>k;
	if(k % 2 == 0){
		cout<<"-1"<<endl;
		return 0;
	}
	else if(k == 1 || k == 7){
		cout<<"1"<<endl;
		return 0;
	}
	int pre_num = 7;
	func(pre_num,k);
	
	if(ans < k * 2){
		cout<<ans<<endl;
	}
	else cout<<"-1"<<endl;
	return 0;
}


