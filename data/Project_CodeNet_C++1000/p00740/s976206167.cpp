#include <iostream>
#include <algorithm>

using namespace std;

int check(int a[51], int n)
{
	int c=0, r=-1;
	
	for(int i = 0; i < n; i++){
		if(a[i] > 0){
			c++;
			r = i;
		}
	}
	if(c > 1){
		r = -1;
	}
	
	return r;
}

int main()
{
	int n, p, s, t, a[51];
	
	while(1){
		cin >> n >> p;
		if(n == 0 && p == 0){
			break;
		}
		fill(a, a+51, 0);
		t = 0;
		bool f = true;
		for(int i = 0; i < 1000000; i++){
			if(p == 0){
				s = check(a, n);
				if(s != -1){
					cout << s << endl;
					f = false;
					break;
				}
				p += a[t];
				a[t] = 0;
			} else {
				p--;
				a[t]++;
			}
			
			t++;
			if(n == t){
				t = 0;
			}
		}
		
		if(f){
			cout << 0 << endl;
		}
	}
	
	return 0;
}