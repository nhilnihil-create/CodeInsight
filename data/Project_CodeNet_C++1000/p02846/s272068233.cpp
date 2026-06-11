#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>
#include<iomanip>
#include<sstream>
#include<vector>
#include<stack>
#include<math.h>
#include<queue>
#include<complex>
#include<random>
#include<ctime>
using namespace std;



const long long int mod=1000000007;
const long long int INF=99999999999999999;

long long int t1,t2,a1,a2,b1,b2,sa,res;
string str;
int main() {
	cout << fixed << setprecision(18);
	cin>>t1>>t2>>a1>>a2>>b1>>b2;
	if(t1*a1+t2*a2==t1*b1+t2*b2){
		cout<<"infinity";
		return 0;
	}
	if(t1*a1+t2*a2<t1*b1+t2*b2){
		swap(a1,b1);
		swap(a2,b2);
	}
	if((a1-b1)>0&&(a2-b2)>0){
		cout<<0;
		return 0;
	}
	
	if(a1>b1){
		cout<<0;
		return 0;
	}
	sa=t1*a1+t2*a2-(t1*b1+t2*b2);
	res=(t1*(b1-a1))/sa;
	if(sa*res==t1*(b1-a1)){
		res=2*res;
	}else{
		res=2*res+1;
	}
	
	//cout<<"sa"<<sa<<endl;
	//cout<<"t1(b1-a1)"<<t1*(b1-a1)<<endl;
	if(res<=0){res=0;}
	cout<<res;
} 
