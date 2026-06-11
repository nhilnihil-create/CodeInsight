#include<bits/stdc++.h>
#define ll long long
#define fastio  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MOD=1000000007;
#define PI acos(-1)
using namespace std;
int main(){
    int a[3][3],b[3][3];
    for(int i=0 ; i < 3 ; i++){
    	for(int j=0 ; j < 3 ; j++){
    	cin >> b[i][j];
    	  a[i][j]=0;
      }
	}
	int q; cin >> q ;
	while(q--){
		int x; cin >> x ;
		for(int i=0 ; i < 3 ; i++){
			for(int j=0 ; j < 3 ; j++){
				if(b[i][j]==x)
				   a[i][j]=1;
			}
		}
	}
	if(a[0][0] == 1 && a[1][1]==1 && a[2][2]==1 || a[0][2] == 1 && a[1][1]==1 && a[2][0]==1)
	 cout << "Yes" << endl;
	 else if(a[0][0]==1 && a[0][1]==1 && a[0][2]==1 || a[1][0]==1 && a[1][1]==1 && a[1][2]==1 ||a[2][0]==1 && a[2][1]==1 && a[2][2]==1 ) 
	 cout << "Yes" << endl;
	 else if(a[0][0]==1 && a[1][0]==1 && a[2][0]==1 ||a[0][1]==1 && a[1][1]==1 && a[2][1]==1 ||a[0][2]==1 && a[1][2]==1 && a[2][2]==1 )
	 cout << "Yes" << endl;
	 else cout << "No";
}