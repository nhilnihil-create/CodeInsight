#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
typedef long long int LL;

int n, k, c;
string s;
int l[maxn], r[maxn];

int main(){
	scanf("%d %d %d", &n, &k, &c);
    cin>>s;
    
	memset(l, 0, sizeof(l));
	memset(r, 0, sizeof(r));
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == 'o'){
			l[i] = ++cnt;
			i += c;
		}
	}
	cnt = k;
	for(int i = n-1; i >= 0; i--){
		if(s[i] == 'o'){
			r[i] = cnt--;
			i -= c;
		}
	}
	for(int i = 0; i <n; i++){
		if(r[i] == l[i] && r[i] > 0){
			printf("%d\n", i+1);
		}
	}
}
