#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
	int wan, n, winner;
	while(cin>>n>>wan, wan||n){
		int cnd[50]={0};
		for(int i = 0;;i=(i+1)%n){
			if(wan>0){
				wan--,cnd[i]++;
				if(wan==0){
					bool win=1;
					rep(j, n){
						if(i==j)continue;
						if(cnd[j]>0)win=0;
					}
					if(win){
						winner = i; break;
					}
				}
			}else wan+=cnd[i], cnd[i]=0;
		}
		cout<<winner<<endl;
	}
}