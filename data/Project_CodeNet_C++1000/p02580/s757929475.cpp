#include<bits/stdc++.h>

using namespace std;

long long n,m,k,row[300005],col[300005],x[300005],y[300005];
long long rowmax,colmax;
long long rowmaxsize,colmaxsize;
long long resset;
long long result;
int main(){
	cin >> n >> m >> k;
	for(int i = 0;i < k;i++){
		cin >> x[i] >> y[i];
		row[x[i]]++;
		col[y[i]]++;
	}
	
	for(int i = 1;i <= n;i++)
		rowmax = max(rowmax,row[i]);
	for(int i = 1;i <= m;i++)
		colmax = max(colmax,col[i]);
		
		
	for(int i = 1;i <= n;i++)
		if(row[i] == rowmax)
			rowmaxsize++;

	for(int i = 1;i <= m;i++)
		if(col[i] == colmax)
			colmaxsize++;
			
	for(int i = 0;i < k;i++){
		if(row[x[i]] == rowmax && col[y[i]] == colmax)
			resset++;
	}
	
	if(resset < rowmaxsize*colmaxsize)
		cout << rowmax+colmax << endl;
	else
		cout << rowmax+colmax - 1<< endl;
		
	
	return 0; 
} 