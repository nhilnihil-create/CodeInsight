#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	string s;
	long long k, ans = 0, end = 0, cnt = 0, d = 0, f = 0;

  	cin >> s >> k;
  	long long l = s.size();
	if(s[0] == s[l-1]) end = 1;
    if(1<l){
      for(int i=l-1;1<=i;i--){
          if(s[l-1]==s[i]){
              d++;
          }else{
              break;
          }
      }
    }
    if(1<l&&end == 1){
      for(int i=0;i<l-d;i++){
          if(s[l-1]==s[i]){
              f++;
          }else{
              break;
          }
      }
    }
	int c=1;
	if(end == 0){
		while(c < l){
			if(s[c-1] == s[c]){
				cnt++;
				c+=2;
			}else{
				c++;
			}
		}
	}else{
		c = f;
		while(c < l-d){
			if(s[c-1] == s[c]){
				cnt++;
				c+=2;
			}else{
				c++;
			}
		}	
	}
	if(end == 0){
		ans = cnt*k;
	}else{
		ans = cnt*k+((d+f)/2)*(k-1);
	}
	if(1<d*end){
		ans+=(d/2);
	}
	if(1<f*end){
		ans+=(f/2);
	}
	if(d+end==l) ans = k*l/2;
		
	cout << ans <<endl;
}
