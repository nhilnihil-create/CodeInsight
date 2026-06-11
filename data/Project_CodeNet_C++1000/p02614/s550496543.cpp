#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
int h,w,k;
string grid[6];
int main()
{
	cin>>h>>w>>k;
	string state;
	for(int i=0;i<h;i++) {
		cin>>state;
		grid[i]=state;
	}
	int sol=0;
	//grid created!
	for(int rowMask=0;rowMask<=(1<<h)-1;rowMask++)
		for(int columnMask=0;columnMask<=(1<<w)-1;columnMask++) {
			int cnt=0;
			for(int i=0;i<h;i++) {
				for(int j=0;j<w;j++) {
					//check if we painted this row red, and this column red, and check if black or white
					if((rowMask>>i&1)==0&&(columnMask>>j&1)==0&&grid[i][j]=='#')
						cnt++;
				}
			}
			if(cnt==k)
				sol++;
		}
	cout<<sol<<endl;
		
}

