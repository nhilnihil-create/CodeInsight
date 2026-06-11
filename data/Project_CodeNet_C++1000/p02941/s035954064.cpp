#include<bits/stdc++.h>
using namespace std;

const int _ = 2e5 + 3;
int A[_] , B[_] , N;
struct cmp{bool operator ()(int x , int y){return A[x] > A[y];}};
multiset < int , cmp > pos;

int main(){
	ios::sync_with_stdio(0); cin >> N;
	for(int i = 1 ; i <= N ; ++i) cin >> B[i];
	for(int i = 1 ; i <= N ; ++i){cin >> A[i]; pos.insert(i);}
	long long stp = 0;
	while(!pos.empty()){
		int t = *pos.begin(); pos.erase(pos.begin());
		if(A[t] < B[t]){puts("-1"); return 0;}
		if(A[t] > B[t]){
			int num = A[t == 1 ? N : t - 1] + A[t == N ? 1 : t + 1];
			if(A[t] % num == B[t] % num){stp += (A[t] - B[t]) / num; A[t] = B[t];}
			else{
				if(A[t] < num){puts("-1"); return 0;}
				stp += A[t] / num; A[t] %= num;
				if(A[t] < B[t]){puts("-1"); return 0;}
				pos.insert(t);
			}
		}
	}
	printf("%lld\n" , stp);
	return 0;
}
