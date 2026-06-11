#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int main()
{
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	int a, b, m;
	cin >> a >> b >> m;
	vector<int> p;
	int i;
	int minp, minq;
	for(i=0; i<a; i++){
		int n;
		cin >> n;
		p.push_back(n);
		//minp = min(minp, n);
	}
	vector<int> q;
	for(i=0; i<b; i++){
		int n;
		cin >> n; 
		q.push_back(n);
		//minq = min(minq, n);
	}
	minp = *min_element(p.begin(), p.end());
	minq = *min_element(q.begin(), q.end());
	//map<int, int> s;
	//int m;
	//cin >> m;
	//sort(p.begin(), p.end());
	//sort(q.begin(), q.end());
	int ans = minp+minq;
	for(i=0; i<m; i++){
		int j, k, l;
		cin >> j >> k >> l;
		j--, k--;
		//s[j]++;
		//s[k]++;
		//if(s[j]>1 || s[k]>1) break;
		//else{
		//cout << p[j-1] << " " << q[k-1] << endl;
		//tmp = p[j-1]  + q[k-1] - l;
		ans = min(ans, p[j]+q[k]-l);
	}
	cout << ans << endl;
	return 0;
}
		
