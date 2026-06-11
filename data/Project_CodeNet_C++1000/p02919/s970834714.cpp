#include <bits/stdc++.h>
using namespace std;

// 参考：https://ykmaku.hatenablog.com/entry/2019/09/09/233033

int main()
{
	int n;
	cin>>n;
	vector<int> p(n),pos(n+1);
	for(int k=0;k<n;k++) cin>>p[k];
  // pos[p[k]] p[k]の位置を記録(1-origin)
  // p={2,3,1} -> pos={(0),3,1,2}
	for(int k=0;k<n;k++) pos[p[k]] = k+1;

	long ans = 0;
  //インデックスを格納するための集合
	multiset<int> s;
  //境界条件のために番兵を追加
	s.insert(0);
	s.insert(0);
	s.insert(n+1);
	s.insert(n+1);
  // Pi=XLRを固定してΣPi*CiのCiを求める
  // pの要素が大きい順にみていく
  //
	for (int pi = n; pi >= 1; pi--){
    // i:Piの位置(インデックス)
    long i=pos[pi];
    // it:sの中でi以上の値を持つ最初のインデックスを返す
		auto it = s.lower_bound(i);
    // y: j>iかつp[i]<p[j]を満たすインデックスjの中で最小のもの
		long y = *it;
    // z: j>iかつp[i]<p[j]を満たすインデックスjの中で二番目に小さいもの
		it++;
		long z = *it;
    // x: j<iかつp[i]<p[j]を満たすインデックスjの中で最大のもの
		it--;
		it--;
		long x = *it;
    // w: j<iかつp[i]<p[j]を満たすインデックスjの中で二番目に大きいもの
		it--;
		long w = *it;
    //cout<<w<<" "<<x<<" "<<i<<" "<<y<<" "<<z<<endl;
    long ci =(y-i)*(x-w) + (z-y)*(i-x);
		ans += pi *ci;
    // iをsに追加
    // sは自動で昇順にソートされる
		s.insert(i);
	}
  // p={2,3,1}のとき
  // s={0,0,4,4}
  // pi=3 -> i=2 *it=y=4 z=4 x=0 w=0 ci=0
  // s={0,0,2,4,4}
  // pi=2 -> i=1 y=2 z=4 x=0 w=0 ci=2
  // s={0,0,1,2,4,4}
  // pi=1 -> i=3 y=4 z=4 x=2 w=1 ci=1
  // s={0,0,1,2,3,4,4}
  // と遷移する
	cout<<ans<<endl;

	return 0;
}
