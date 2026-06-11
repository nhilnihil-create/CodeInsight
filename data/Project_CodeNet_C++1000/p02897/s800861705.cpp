#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	int n;
	cin>>n;
    double ans;
    if(n&1){
    	ans = (n+1)/2;
    } else{
    	ans = n/2;
    }
   // cout<<ans<<endl;
   ans = ans/n*1.0;
   cout<< fixed <<showpoint;
   cout<< setprecision(6);
   cout <<ans<<endl;

}