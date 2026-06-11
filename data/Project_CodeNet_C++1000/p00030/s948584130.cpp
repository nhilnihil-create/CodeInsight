using namespace std;
#include <iostream>
#include <string>
#include <set>
#include <functional>
#include <vector>
#include <algorithm>

int main()
{
	int n,s;
	while(cin>>n>>s&&(n||s)){
		if(!n){cout<<"0"<<endl;continue;}
		int comb=(1<<n)-1,ans=0;
		while(comb<1<<10){
			int sum=0;
			for(int i=0;i<10;i++){
				sum+=i*((comb>>i)&1);
			}
			//cout<<"sum:"<<sum<<endl;
			if(sum==s)ans++;
			int x=comb&-comb,y=comb+x;
			comb=((comb&~y)/x>>1)|y;
		}
		cout<<ans<<endl;
	}
    return 0;
}