#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define mod 2019
#define ll long long
int main(){

	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    string s;
    cin>>s;
    int n = s.length();
    std::vector<int> cnt_suf(mod);
    int ans = 0;
    int suf = 0;
    int power_of_ten = 1;
    cnt_suf[0]++;
    for (int i = n-1; i >=0; --i)
    {
    	int digit = s[i] - '0';
    	suf = (suf + (digit * power_of_ten)) % mod;
    	power_of_ten = (power_of_ten * 10) % mod;
        cnt_suf[suf]++;
    }

    for (int i = 0; i < mod; ++i)
    {
    	if(cnt_suf[i] >= 2){
    		ans += (cnt_suf[i] * (cnt_suf[i] - 1))/2;
    	}
    }
    cout<<ans;
}