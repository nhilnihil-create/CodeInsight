#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;
int T[N+100],F[N+100];
string c[N+100];

int main()
{
	string s,f = "",b = "";
	cin >> s;
	int q,total = 0,cur = 0;
	cin >> q;
	for(int i=1;i<=q;i++)
	{
		cin >> T[i];
		if(T[i]==1){
			total++;
		}
		else{
			cin >> F[i] >> c[i];
		}
	}
	for(int i=1;i<=q;i++)
	{
		if(T[i]==1){
			cur++;
		}
		else{
			if(F[i]==1){
				if((cur&1)==(total&1)){
					f += c[i];
				}
				else{
					b += c[i];
				}
			}
			else{
				if((cur&1)==(total&1)){
					b += c[i];
				}
				else{
					f += c[i];
				}
			}
		}
	}
	reverse(f.begin(),f.end());
	if(total&1){
		reverse(s.begin(),s.end());
	}
	cout << f << s << b << "\n";
}
