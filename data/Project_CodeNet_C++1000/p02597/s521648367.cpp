#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
typedef long long ll;
typedef pair<int, int> P;
 
int main(){
	  int n;
	    cin >> n;
			string c;
			cin >> c;
	    
			int nr=0;
			rep(i,n){
				if(c.at(i)=='R') nr++;
			}

			int RinW=0, WinR=0;
			rep(i, n){
				if(i<nr){
					if(c.at(i)!='R') WinR++;
				}
				else{
					if(c.at(i)!='W') RinW++;
				}
			}

			cout << max(RinW, WinR) << endl;
	    return 0;
}
