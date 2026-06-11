#include <bits/stdc++.h>

using namespace std;

int func(int n, int c[], int r_num){
	int re = 0;
	for(int i = 0; i < r_num; i++){
		if(c[i] != 1) re++;
	}
	return re;
}

int main(void)
{
	int n;
	cin>>n;
	int c[n];
	int r_num = 0;
	char color;
	for(int i = 0; i < n; i++){
		cin>>color;
		if(color == 'R'){
			c[i] = 1;
			r_num++;
		}
		else if(color == 'W') c[i] = 2;
	}
	int ans = func(n,c,r_num);
	cout<<ans<<endl;
	return 0;
}

