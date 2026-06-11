#include <iostream>
#include <queue>

using namespace std;

struct  pos {
	int x, y;
	pos(int _x, int _y) { x = _x; y = _y;}
};

int a[50][50];

void ans(int p,int q,int h,int w);

int main(){
	int H,W,count;
	while(1){
		count=0;
		cin >> H;
		cin >> W;
		if(H==0&&W==0){
			break;
		}
		for(int i=0;i<W;i++){
			for(int j=0;j<H;j++){
				cin >> a[i][j];
			}
		}
		
		for(int i=0;i<W;i++){
			for(int j=0;j<H;j++){
				if(a[i][j]==1){
					a[i][j]=0;
					ans(i,j,H,W);
					count++;
				}
			}
		}
		cout << count << endl;
	}
	return 0;
}

void ans(int p, int q, int h, int w)
{
	queue<pos> Q;
	Q.push(pos(p, q));
	while (Q.size()) {
		pos b= Q.front();
		Q.pop();
		for (int i=-1;i<=1;i++) {
			for (int j=-1;j<=1;j++) {
				if(0<=b.x+i&&b.x+i<w&&0<=b.y+j&&b.y+j<h){
					if(a[b.x+i][b.y+j]==1){
						a[b.x+i][b.y+j]=0;
						Q.push(pos(b.x+i,b.y+j));
					}
				}
			// mawariwomiru
			}
		}
	}
}


/*
void ans(int p,int q,int h,int w){
	for(int i=-1;i<=1;i++){
		for(int j=-1;j<=1;j++){
			if(0<=p+i&&p+i<h&&0<=q+j&&q+j<w){
				if(a[p+i][q+j]==1){
					a[p+i][q+j]=0;
					Q.push(pos(p+i,q+j));
				}
			}
		}
	}
	if(Q.size()){
		pos b=Q.front();
		Q.pop();
		ans(b.x,b.y,h,w);
	}
}*/
				
	