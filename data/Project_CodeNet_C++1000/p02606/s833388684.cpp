#include<bits/stdc++.h>

using namespace std;
#define pb push_back
#define loop(ii,nn) for(int ii=0;ii<nn;ii++)
typedef vector<int> vi;


int main(){
		int l,r,d;cin>>l>>r>>d;
		int count =0;
		for(int i=l;i<=r;i++)
		if(i%d==0)
		count++;
		
		cout<<count<<endl;

	return 0;
}
