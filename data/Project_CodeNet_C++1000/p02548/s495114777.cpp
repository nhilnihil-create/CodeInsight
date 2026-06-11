#include<bits/stdc++.h>
#define ll           long long int
#define pb           push_back
#define F            first
#define S            second
using namespace std;
	int main(){
        int t,n,a,b,c,ans=0;
        cin>>n;
        for( a=1;a<n;a++){
            for( b=1;a*b<n;b++){
                ans++;
            }
        }
        cout<<ans<<endl;
	}
