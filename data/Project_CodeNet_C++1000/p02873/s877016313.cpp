#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	string s;

  	cin >> s;
  	
	long long n = s.size(), ans = 0;
	long long pcnt = 0, mcnt = 0, p = 0;
	for(long long i=0;i<n;i++){
		if(i<n-1&&s[i] == '<'){
			if(mcnt == 0){
				pcnt++;
			}else{
				ans += mcnt*(mcnt+1)/2;
				if(p>mcnt) ans += (p - mcnt);
				pcnt = 1;
				mcnt = 0;
				p = 0;
			}
		}else if(i<n-1&&s[i] == '>'){
			if(pcnt == 0){
				mcnt++;
			}else{
				ans += (pcnt-1)*pcnt/2;
				p = pcnt;
				pcnt = 0;
				mcnt++;
			}
		}else if(i == n-1&&s[i] == '<'){
			if(mcnt == 0){
				pcnt++;
				ans += pcnt*(pcnt+1)/2;
			}else{
				ans += mcnt*(mcnt+1)/2;
				if(p > mcnt) ans += (p - mcnt);
				ans++;
			}
		}else{
			if(pcnt == 0){
				mcnt++;
				ans += mcnt*(mcnt+1)/2;
			}else{
				ans += pcnt*(pcnt+1)/2;
			}
		}
	}
	
	cout << ans <<endl;
}

