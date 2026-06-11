#include <iostream>

using namespace std;

int max(int a,int b){
	if(a>=b)return a;
	else return b;
}

int min(int a,int b){
	if(a<=b) return a;
	else return b;
}

int main(){
	int data[500][500];
	int posX[201];
	int posY[201];

	int dx[4]={-1,0,1,0};
	int dy[4]={0,-1,0,1};
	int n;

	while(cin>>n){
		if(n==0)break;

	for(int i=0;i<500;i++){
		for(int j=0;j<500;j++){
			data[i][j]=-1;
		}
	}

	for(int i=0;i<201;i++){
		posX[i]=-1;
		posY[i]=-1;
	}

	
	data[250][250]=0;
	posX[0]=250;
	posY[0]=250;

	for(int i=1;i<n;i++){
		int num,pos;
		cin>>num>>pos;

		data[posY[num]+dy[pos]][posX[num]+dx[pos]]=i;
		posY[i] = posY[num]+dy[pos];
		posX[i] = posX[num]+dx[pos];

	}

	int maxX=0;
	int minX=100000;
	int maxY=0;
	int minY=100000;

	for(int i=0;i<n;i++){
	//	cout<<"i="<<i<<" X= "<<posX[i]<<" Y= "<<posY[i]<<endl;
		maxX=max(posX[i],maxX);
		maxY=max(posY[i],maxY);
		minX=min(posX[i],minX);
		minY=min(posY[i],minY);
	}

	cout<<maxX-minX+1<<" "<<maxY-minY+1<<endl;

	}

	return 0;
}