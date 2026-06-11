#include <bits/stdc++.h>
using namespace std;
#define r(i,n) for(auto i=0;i<n;i++)
#define s(c) static_cast<int>((c).size())

int main(){
	int n, m;
	cin >> n >> m;

	set<int> A[n+1];
	int v1, v2;
	r(i, m){
		cin >> v1 >> v2;

		A[v1].insert(v2);
		A[v2].insert(v1);
	}

	//初期の未到達状態は0
	//必要に応じて連結成分ごとに1から順に分類
	int group[n]{};
	stack<int> s;

	int q, groupNum = 0, gn1, gn2;
	cin >> q;
	r(i, q){
		cin >> v1 >> v2;

		if(group[v1] == 0 && group[v2] == 0){
			groupNum++;

			s.push(v1);
			group[v1] = groupNum;

			while(!s.empty()){
				int v = s.top();
				int size = s(A[v]);
				for(int tmp : A[v]){
					if(!group[tmp]){
						s.push(tmp);
						group[tmp] = groupNum;
					}else{
						size--;
					}
				}
				if(!size)
					s.pop();
			}
		}

		gn1 = group[v1];
		gn2 = group[v2];
		//printf("group[%d]=%d, group[%d]=%d: ", v1, gn1, v2, gn2);
		printf(gn1 == gn2 ? "yes\n" : "no\n");
	}

	return 0;
}
