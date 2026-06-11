#include<bits/stdc++.h>
#define boost  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int 
using namespace std;
void sol(){
  	int h,n;
  	cin >>h >> n;
  	int a[n];
  	int sum=0;
  	for(int i=0;i<n;i++){
  		cin >>a[i];
  		sum+= abs(a[i]);
  	}
  	if (sum>=h){
  		cout << "Yes";
  	}
  	else{
  		cout << "No";
  	}
 	}


int main()
{
	boost;
	sol();
}