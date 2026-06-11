#include <iostream>
using namespace std;
const int max_num=10;

char a[max_num][max_num];
int h,w,k;
int count=0;

void inputnumbers(){
	cin >> h >> w >> k;
	for(int i=0;i<h;i++)
			cin >> a[i];
}

void printnumbers(char c[][max_num]){
	cout << h << ' ' << w << ' ' << k << endl;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++)
		cout << c[i][j] ;
	cout << endl;
	}

}
void printmatrix(char c[][max_num]){
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++)
		cout << c[i][j] ;
	cout << endl;
	}
}

void printrawcol(bool *rawcol){
	for(int i=0;i<h+w;i++)
		cout << (int) rawcol[i];
	cout << endl;
}

int countnumber(char c[][max_num]){
	int num=0;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(*(*(c+i)+j)=='#')
				num++;
		}
	}
	return num;
}


void resetraw(int i,char c[][max_num]){
	for(int j=0;j<w;j++)
		c[i][j]='&';
}

void resetcolumn(int j,char c[][max_num]){
	for(int i=0;i<h;i++)
		c[i][j]='!';
}

int rawtolinear(int raw){
	return raw;
}
int coltolinear(int col){
	return h+col;
}

void lineartorc(int l,int *raw,int *col){
	if(l<h){
		*raw=l;
		*col=-1;
	}
	else{
		*raw=-1;
		*col=l-h;
	}
}

int countsolvnum(bool *rawcol,char c[][max_num],int *n){
	char b[max_num][max_num];
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
			b[i][j]=c[i][j];
	for(int i=0;i<h;i++)
		if(rawcol[rawtolinear(i)])
			resetraw(i,b);
	for(int j=0;j<w;j++)
		if(rawcol[coltolinear(j)])
			resetcolumn(j,b);
	//printnumbers(b);
	*n=countnumber(b);
	return *n;
}
int countsolvnum(bool *rawcol,char c[][max_num]){
	int n;
	char b[max_num][max_num];
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
			b[i][j]=c[i][j];
	for(int i=0;i<h;i++)
		if(rawcol[rawtolinear(i)])
			resetraw(i,b);
	for(int j=0;j<w;j++)
		if(rawcol[coltolinear(j)])
			resetcolumn(j,b);
	n=countnumber(b);
	//printrawcol(rawcol);
	//printmatrix(b);
	//cout << n << endl;
	return n;
}



void copymatrix(char d[][max_num],char s[][max_num]){
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
			d[i][j]=s[i][j];
}

bool dfs(int i,bool *rawcol){
	bool hantei=true;
	char b[max_num][max_num];
	copymatrix(b,a);
	bool rawcolcopy[2*max_num];
	//cout << "dfs i=" << i << endl;
	for(int i=0;i<h+w;i++)
		rawcolcopy[i]=rawcol[i];
	if(i==h+w){
		if(countsolvnum(rawcolcopy,a)==k)
			count++;
	for(int i=0;i<h+w;i++)
		if(rawcol[i]==false)
			hantei=false;
	return hantei;
	}
	if(dfs(i+1,rawcolcopy))
		return false;
	if((rawcolcopy[i]=true) && dfs(i+1,rawcolcopy))
		return true;
	return false;
}


int main() {
	bool rowcol[2*max_num];

	inputnumbers();
	//printnumbers(a);
	//cout << countnumber(a) << endl;

	/*for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
			cout<<rawtolinear(i)<<' '<<coltolinear(j)<<' ' <<endl;
	for(int i=0;i<h+w;i++){
		int r,c;
		lineartorc(i,&r,&c);
		cout <<i<<' '<< r << ' ' << c <<endl;
	}*/

	for(int i=0;i<h+w;i++)
		rowcol[i]=false;
	//cout << "total = " << count << endl;
	dfs(0,rowcol);
	cout << count << endl;

	return 0;
}
