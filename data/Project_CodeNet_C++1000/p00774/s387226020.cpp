#include <bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)

int read(){
	int i;
	scanf("%lld",&i);
	return i;
}

signed main(){
	while(true){
		int H=read();
		if(H==0) break;
		
		int table[H][5]={0};
		REP(i,H){
			REP(j,5){
				table[i][j]=read();
			}
		}
		
		int point=0;
		while(true){
			REP(i,H){
				int count=1;
				int tmpvalue=0;
				FOR(j,1,5){
					if(table[i][j]==table[i][j-1]){
						count++;
						tmpvalue=table[i][j];
					}
					else if(count>=3){
						REP(k,count){
							table[i][j-1-k]=0;
						}
						point+=count*tmpvalue;
						count=1;
					}
					else count=1;
					
					if(j==4&&count>=3){
						REP(k,count){
							table[i][j-k]=0;
						}
						point+=count*tmpvalue;
						count=0;
					}
				}
			}
			bool flag=true;
			REP(j,5){
				for(int i=H-2;i>=0;i--){
					for(int k=0;k+i<H-1;k++){
						if(table[i+k][j]!=0&&table[i+1+k][j]==0){
							flag=false;
							table[i+1+k][j]=table[i+k][j];
							table[i+k][j]=0;
						}
					}
				}
			}
			
			/*REP(i,H){
				REP(j,5){
					cout << table[i][j];
				}
				cout << endl;
			}
			cout << endl;*/
			if(flag) break;
		}
		cout << point << endl;
	}
}