#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <stack>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

void i_sort(int* a, int n , int g , int* count ){
	int j,v;
	for(int i=g ; i<n ;++i){
		v=a[i];
		j=i-g;
		while(j>=0 && a[j]>v){
			a[j+g]=a[j];
			j=j-g;
			a[j+g]=v;
			(*count)++;
		}
	}
}

void s_sort(int* a , int n ,  int* cnt){
	*cnt=0;
	vector<int> g;
	int m=0,tmp=1;
	for(;;){
		g.push_back(tmp);
		tmp=tmp*4+1;
		m++;
		if(tmp>=n) break;
	}
	cout << m << endl;
	reverse(g.begin(), g.end());
	for(int i=0;i<m;++i){
		i_sort(a , n , g[i] , cnt);
		cout << g[i];
		if(i!=m) cout << " ";
	}
	cout << endl;
}

int main(){
	int n,count;
	cin >> n;
	int* a = new int [n];
	for(int i=0;i<n ; ++i){
		cin >> a[i];
	}
	s_sort(a,n,&count);
	cout << count << endl;
	for(int i=0;i<n ; ++i){
		cout << a[i] << endl;
	}
	delete [] a;
	return 0; 
}