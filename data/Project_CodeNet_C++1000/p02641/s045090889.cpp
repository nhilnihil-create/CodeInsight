#include<bits/stdc++.h>
using namespace std;
int a[105];
bool b[105]={0};
	


int main(){
	int x,y;
	cin>>x>>y;
	if(y==0){
		cout<<x<<endl;
		return 0;
	}

	for(int i=1;i<=y;i++){
		cin>>a[i];
		b[a[i]]=true;
	}

	int i=101;
	int max=100005;
	int ans=102;
	for(int n=101;n>=0;n--){
	
		if(!b[i]){
			if(max>=abs(i-x)){
				max=abs(i-x);
				
				if(ans>i){
					ans=i;
				}
				i--;
			}
		}
		else
		{
			i--;
		}
	}
	cout<<ans<<endl;
}