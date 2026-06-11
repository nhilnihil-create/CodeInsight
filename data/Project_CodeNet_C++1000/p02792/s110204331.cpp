#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	long long ans = 0;
	for(int i=1;i<=n;i++){
		int head, tail;
		tail = i%10;
		if(i<10){
			head = i;
		}else if(i<100){
			head = i/10;
		}else if(i<1000){
			head = i/100;
		}else if(i<10000){
			head = i/1000;
		}else if(i<100000){
			head = i/10000;
		}else{
			head = i/100000;
		}
		if(tail==0) continue;
		if(head == tail){
			if(head<=n) ans++;
		}
		if(n<tail*10+head){
			continue;
		}else{
			ans++;
		}
		if(n<tail*100+head){
			continue;
		}else if(n<tail*100+90+head){
			int k= n-tail*100;
			k /= 10;
			ans += k;
			if(tail*100+k*10+head<=n){
				ans++;
			}
		}else{
			ans += 10;
		}
		if(n<tail*1000+head){
			continue;
		}else if(n<tail*1000+990+head){
			int k =  n-tail*1000;
			k /= 10;
			ans += k;
			if(tail*1000+k*10+head<=n){
				ans++;
			}
		}else{
			ans += 100;
		}
		if(n<tail*10000+head){
			continue;
		}else if(n<tail*10000+9990+head){
			int k = n- tail*10000;
			k/= 10;
			ans += k;
			if(tail*10000+k*10+head<=n) ans++;
		}else{
			ans += 1000;
		}
		if(n<tail*100000+head){
			continue;
		}else if(n<tail*100000+99990+head){
			int k=n-tail*100000;
			k /= 10;
			ans += k;
			if(tail*100000+k*10+head<=n) ans++;
		}else{
			ans += 10000;
		}
	}
	cout<<ans<<endl;
}
