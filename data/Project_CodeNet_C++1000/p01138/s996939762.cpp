#include <cstdio>
#include <queue>
#include <vector>
#include <map>
using namespace std;

typedef pair<int,int> P;

int main(){
	int n;
	while( scanf("%d", &n) , n ){
		// (時刻,列車の増減) のペアを格納する優先度つきキュー
		// 時刻の早いほうから順に出てくる.
		priority_queue< P , vector<P> , greater<P> > q;
		
		for(int i=0 ; i < n ; i++ ){
			int h1, m1, s1, h2, m2, s2;
			scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
			int t1 = h1 * 60 * 60 + m1 * 60 + s1;
			int t2 = h2 * 60 * 60 + m2 * 60 + s2;
			q.push( P(t1,+1) );
			q.push( P(t2,-1) );
		}
		int ans = 0, cnt = 0;
		while( !q.empty() ){
			cnt += q.top().second;
			q.pop();
			ans = max( ans , cnt );
		}
		printf("%d\n", ans);
	}
}