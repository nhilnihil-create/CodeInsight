#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define mp make_pair
#define inf 1000000007
#define int long long
using namespace std;
ll p2[61];
ll bt[114514][60];
vector<ll> v;
ll check_bit(ll N,int POS){return (N & (1LL<<POS));}
ll gaussian_elimination()
{
    int n=v.size();
    int ind=0;  // Array index
    for(int bit=log2(v[0]);bit>=0;bit--)
    {
        int x=ind;
        while(x<n&&check_bit(v[x],bit)==0)
          x++;
        if(x==n)
          continue; // skip if there is no number below ind where current bit is 1
        swap(v[ind],v[x]);
        for(int j=0;j<n;j++)
        {
            if(j!=ind&&check_bit(v[j],bit))
                v[j]^=v[ind];
        }
        ind++;
    }
    ll ANS=v[0];
    for(int i=1;i<n;i++)
      ANS=max(ANS,ANS^v[i]);
    return ANS;
}
signed main(){
	int n; cin>>n;
	vector<int> a;
	vector<int> deke;
	int alx=0;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a.pb(x);
		alx = alx^x;
	}
	int ans = 0;
	p2[0]=1;
	for(int i=1;i<=60;i++){
		p2[i]=p2[i-1]*2;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<=59;j++){
			if( a[i] % p2[j+1] >= p2[j])bt[i][j] = 1;
		}
	}
	vector<int> dame;
	for(int i=59;i>=0;i--){
		if( alx % p2[i+1] >= p2[i]){
			ans += p2[i];
		}
		else{
			dame.pb(i);
		}
	}
	for(int i=0;i<=n;i++){
		v.pb(0);
	}
	for(int i=0;i<dame.size();i++){
		int cd = dame[i];
		for(int k=0;k<n;k++){
			if(bt[k][cd]==1)v[k]+=p2[cd];
		}
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	ans += gaussian_elimination()*2;
	cout<<ans<<endl;
	return 0;
}