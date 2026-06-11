
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <cmath>
#include <iomanip> 
#include <bits/stdc++.h>
using namespace std;
double pi=3.14159265358979323846264338;
#include <bits/stdc++.h>
 
#ifndef LOCAL
#define cerr dolor_sit_amet
#endif
 
#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second
#define all(x) (x).begin(), (x).end()
 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const int MOD = 1000000007;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};
 
template<typename T> T& updMin(T& a, T const& b) { if (b < a) a = b; return a; }
template<typename T> T& updMax(T& a, T const& b) { if (a < b) a = b; return a; }
 
// ========================================================================= //
//999977 17 499998
const int ind=6000000;
double h,c,t;
double tem(double cur){
	if((2*cur+3)*labs(t*(2*cur+1)-(cur*(h+c)+h))>(2*cur+1)*fabs(t*(2*cur+3)-((cur+1)*(h+c)+h))){
		return (2*cur+3);
	
	}else {
		if((2*cur-1)*labs(t*(2*cur+1)-(cur*(h+c)+h))<(2*cur+1)*fabs(t*(2*cur-1)-((cur-1)*(h+c)+h))){
			return(2*cur+1);
			//cout<<fabs(t-(cur*(h+c)+h)/(2*cur+1))<<" "<<fabs(t-((cur-1)*(h+c)+h)/(2*cur-1))<<endl;
		}else {
			//cout<<fabs(t-(cur*(h+c)+h)/(2*cur+1))<<" "<<fabs(t-((cur-1)*(h+c)+h)/(2*cur-1))<<endl;
			return (2*cur-1);
			
		}
	}
}
long long culc(){
	long long fr=0;
	long long ls=ind;
	long long mid;
	while(ls>=fr){
		mid=(fr+ls)/2;
		if ((mid*(h+c)+h)/(2*mid+1)<t)ls=mid-1; else if((mid*(h+c)+h)/(2*mid+1)>t)fr=mid+1; else return mid;
	}
	return mid;
}
 
 
 
int main() {
	int n;
	cin>>n;
	int arr[100005];
	for(int i=0;i<=n;i++)cin>>arr[i];
	long long arr2[100005],arr3[100005];
	long long ans=1;
	if((n==0&&arr[0]!=1)||(n!=0&&arr[0]!=0)){
		cout<<"-1"<<endl;
		return 0;
	}
	arr3[n]=arr[n];
	for(int i=n-1;i>=0;i--)arr3[i]=arr[i]+arr3[i+1];
	arr2[0]=1;
	for(int i=1;i<n;i++){
		arr2[i]=arr2[i-1]*2;
		arr2[i]=min(arr2[i],arr3[i]);
		ans+=arr2[i];
		if(arr2[i]<=arr[i]){
			cout<<"-1"<<endl;
          	//cout<<i<<" "<<arr2[i]<<" "<<arr[i]<<endl;
			return 0;
		}
		arr2[i]-=arr[i];
	}
	if(n!=0){
	arr2[n]=2*arr2[n-1];
	if(arr2[n]<arr[n]){
		cout<<"-1"<<endl;
		return 0;
	}
	arr2[n]=arr[n];
ans+=arr2[n];}
	cout<<ans<<endl;
	
	
  return 0;
}

