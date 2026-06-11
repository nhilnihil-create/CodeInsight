#include <bits/stdc++.h>
#define rep(i,n) for(long long i=0; i<n; i++)
#define Rep(i,n) for(long long i=1; i<n; i++)
#define ll long long
#include <math.h>


using namespace std;
#define PI acos(-1)

int main(){
	int K;
	cin >> K;
	string S;
	cin>>S;
	if(S.size()<=K){
	    cout<<S<<endl;
	    return 0;
	}else{
	    rep(i,K){
	        cout<<S[i];
	      if(i==K-1){
	        cout<<"..."<<endl;
	      }
     	}
	 }
	
}

