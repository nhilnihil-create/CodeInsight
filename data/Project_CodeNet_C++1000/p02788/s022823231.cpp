#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    long long n,d,a;
    cin>>n>>d>>a;
    vector<pair<long long,long long>>monsters;
    int x,h;
    for(int i=0;i<n;i++)
    {
        cin>>x>>h;
        monsters.emplace_back(x,h);
    }
    sort(monsters.begin(),monsters.end());
    vector<long long>change(n+1);
    long long ans=0;
    for(int i=0,j=0;i<n;i++)
    {
        while(j<n&&monsters[j].first<=monsters[i].first+2*d)
            j++;
        int bombs=max(((monsters[i].second-change[i]*a+a-1)/a),0LL);
        ans+=bombs;
        change[i]+=bombs;
        change[j]-=bombs;
        change[i+1]+=change[i];
    }
    cout<<ans;
	
	return 0;
}
