/*
    Mbak Sana Dong
    Mbak Chaeyoung Dong
*/
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int cnt[2];
int maxi[2];
int main()
{
	int n,i,j,k,x,y,ans,curr,temp,m;
	int tc;
	cin >> n >> m;
	vector<int> va;
	cnt[1]++;
	maxi[1] = 1;
    temp = m;
    m--;
    for(i=2;i<=temp;i++) {
        cnt[i % 2]++;
        maxi[i % 2] = max(maxi[i % 2], i);
        m--;
    }
    vector<pair<int,int> > chaeng;
    int now = 1;
    i = 0;
    int l, r;
    l = now;
    r = now + maxi[i % 2];
    while(cnt[i % 2] > 0) {
        chaeng.push_back({l, r});
        l++;
        r--;
        cnt[i % 2]--;
    }
    now += maxi[i % 2] + 1;
    i++;
    l = now;
    r = now + maxi[i % 2];
    while(cnt[i % 2] > 0) {
        chaeng.push_back({l, r});
        l++;
        r--;
        cnt[i % 2]--;
    }
    for(auto x : chaeng) cout << x.first << " " << x.second << endl;
	return 0;
}
