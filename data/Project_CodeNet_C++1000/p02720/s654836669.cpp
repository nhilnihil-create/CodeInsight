#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int x=(fr);x<(to);x++)
#define rep(x,to) for(int x=0;x<(to);x++)
#define repr(x,fr,to) for(int x=(fr);x>=(to);x--)
#define all(c) c.begin(),c.end()
#define sz(v) (int)v.size()

using namespace std;
typedef long long  ll; typedef vector<int> VI; typedef pair<int,int> pii;
typedef vector<ll> VL; const int MD = 1e9 + 7;
void dbg(){cerr<<"\n";} template <typename T,typename ...T2> void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }



int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int k;
	cin >>k;
	if(k <=12){cout <<k <<"\n"; return 0;}
	
	queue<ll> q;
	rep2(i,1,10) q.push(i);
	k -=9;
	while(k>0){
		ll cr = q.front(); q.pop();
		if(cr%10 !=0){
			k--; if(k==0){cout <<cr*10 + cr%10 -1 <<"\n"; return 0; }
			q.push(cr*10 + cr%10-1);
		}
		k--;if(k==0){cout <<cr*10 + cr%10 <<"\n"; return 0; }
		q.push(cr*10 + cr%10);
		if(cr%10 !=9){
			k--; if(k==0){cout <<cr*10 + cr%10 +1 <<"\n"; return 0; }
			q.push(cr*10 + cr%10+1);
		}
		
	}
	
	return 0;
}
