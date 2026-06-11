#include <bits/stdc++.h>
using namespace std;

int N, M, Q;
int a[50], b[50], c[50], d[50];
int ans = 0;
int C[20];
void recursive_comb(int s, int rest) {
  if (rest == 0) {
    int A[N];
    for(int i = 0;i<N;i++){
    	A[i] = C[i] - i + 1;
    	//cout << A[i] << ":";
    }
    //cout << endl;
    int tmp = 0;
    for(int i=0;i<Q;i++){
		if(A[b[i] - 1] - A[a[i] - 1] == c[i])tmp += d[i];
	}
	ans = max(tmp, ans);
    return;
  } 
  else {
    if (s < 0) return;
    recursive_comb(s - 1, rest);
    C[rest - 1] = s;
    recursive_comb(s - 1, rest - 1);
  }
}

int main(){
	cin >> N >> M >> Q;
	for(int i=0;i<Q;i++){
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	recursive_comb(N + M - 2, N);
	cout << ans << endl;
}
