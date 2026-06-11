#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define rep(i,n) for(int i=0;i<n;i++)
 
int main() {
	ll X;
  	cin>>X;
  	int flag=0;
  	int a,b;
  	rep(i,1000){
     	for(int j=-1000;j<1000;j++){
         	 if(pow(i,5)-pow(j,5)==X) {
              	 flag=1;
               	 a=i,b=j;
               	 break;
             }
        }
      	if(flag) break;
    }
  	
  	cout<<a<<" "<<b<<endl;
}