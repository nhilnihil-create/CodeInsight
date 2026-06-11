#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
int main(){
    string s;
	cin >> s;
	ll k; cin >> k;
	ll cnt = 1, ans = 0, truer = 1;
	for(ll i = 1; i < s.length(); ++i){
		if(s[0] != s[i]){
			truer = 0;
			break;
		}
	}
	if(truer){
		cout << s.length() * k / 2;
	}else if(s[0] == s[s.length() - 1]){
		ll left = 0, right = s.length() - 1, ans = 0;
		while(s[0] == s[left]){
			left++;
		}
		while(s[s.length() - 1] == s[right]){
			right--;
		}
		right = s.length() - right - 1;
		ans = (left + right) / 2 * (k - 1);
		ll cnt = 1, kanta = 0;
		for(ll i = left; i < s.length() - right; ++i){
			if(s[i] == s[i + 1]){
				cnt++;
				if(i == s.length() - 2){
					kanta += (cnt / 2);
				}
			}else{
				kanta += (cnt / 2);
				cnt = 1;
			}
		}
		kanta *= k;
		cout << ans + left/2 + right/2 + kanta;
	}
	else{
		for(ll i = 0; i < s.length() - 1; ++i){
			if(s[i] == s[i + 1]){
				cnt++;
				if(i == s.length() - 2){
					ans += (cnt / 2);
				}
			}else{
				ans += (cnt / 2);
				cnt = 1;
			}
		}
		ans *= k;
		cout << ans;
	}
    return 0;
}
