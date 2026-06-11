#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<vector>
#include<cmath>
#include<cstring>
#include<cstdio>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define rp(a) while(a--)
#define pb push_back
#define mp make_pair
#define all(in) in.begin(),in.end()
const double PI=acos(-1);
const double EPS=1e-10;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
int main(){
	int a,b;
	while(cin>>a>>b,a||b){
		int d=a*a+b*b;
		bool h=false;
		for(;;d++){
			for(int i=a+1;d-i*i>=0;i++){
				for(int q=i+1;q<151;q++)if(i*i+q*q==d&&i<q){
					h=true;
					cout<<i<<" "<<q<<endl;
					break;
				}
				if(h)break;
			}
			if(h)break;
			a=0;
		}
	}
}