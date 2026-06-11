#include<iostream>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
using namespace std;

int main(){
	int h,w;
	cin>>h>>w;
	int a,b;
	cin>>a>>b;
	int tmp[h][w];
	rep(i,h)rep(j,w)tmp[i][j]=0;
	rep(i,h){
		rep(j,w){
			if(i<b&&j<a)tmp[i][j]=1;
			if(b<=i&&a<=j)tmp[i][j]=1;
		}
	}
	rep(i,h){
		rep(j,w)cout<<tmp[i][j];
		cout<<endl;
	}
	return 0;
}