#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int num;
    cin>>num;
    int flag=0;
    for(int i=1; i<=9; i++){
    	if(num%i==0 && num/i<=9){
    		flag=1;
    		break;
		}
	}
	if(flag)
	 cout<<"Yes";
	else
	 cout<<"No";
	return 0;
}