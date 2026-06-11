#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
using ll = long long;
vector< int64_t > divisor(int64_t n) {
  vector< int64_t > ret;
  for(int64_t i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}
int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &i:a)cin >> i;
	vector<int> cnt(1000001);

	for(int i = 0;i<n;i++)
	{
		cnt[a[i]]++;
	}
	int ans = 0;
	for(int i = 0;i<n;i++)
	{
		auto fac = divisor(a[i]);
		cnt[a[i]]--;
		bool is = true;
		for(int j = 0;j<fac.size();j++)
		{
			if(cnt[fac[j]]>0)
			{
				is = false;
				break;
			}
		}
		cnt[a[i]]++;
		if(is)ans++;
	}
	cout<<ans<<endl;
}
