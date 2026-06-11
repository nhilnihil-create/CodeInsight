#include<iostream>

using namespace std;

int main(){
	int A,B,M;
	cin >> A >> B >> M;
	int a[A],b[B];
	struct {
		int* xp;
		int* yp;
		int c;
	} tickets[M];
	for(int i=0;i<A;i++){
		cin >> a[i];
	}
	for(int i=0;i<B;i++){
		cin >> b[i];
	}
	for(int i=0;i<M;i++){
		int x,y;
		cin >> x >> y >> tickets[i].c;
		tickets[i].xp=&a[x-1];
		tickets[i].yp=&b[y-1];
	}

	int amin=a[0];
	for(const auto& i : a){
		if(i<amin)amin=i;
	}

	int bmin=b[0];
	for(const auto& i : b){
		if(i<bmin)bmin=i;
	}

	int cmin=*tickets[0].xp + *tickets[0].yp - tickets[0].c;
	for(const auto& t : tickets){
		int value=*t.xp + *t.yp - t.c;
		if(value < cmin)cmin=value;
	}

	if(amin+bmin < cmin){
		cout << (amin+bmin) << endl;
	}else{
		cout << cmin << endl;
	}
	return 0;
}
