#include <bits/stdc++.h>
#define ll long long
#define vl vector<ll int>
#define vs vector<string>
#define v vector<int>
#define mi map<int,int>
#define mc map<char,int>

//ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n,dig;
	cin>>n;
	dig=n%10;
	if(dig==2 || dig==4||dig==5||dig==7||dig==9){
		cout<<"hon" <<"\n";
		}
		else if(dig==0||dig==1||dig==6||dig==8){
			cout<<"pon" <<"\n";
			}
			else{cout<<"bon" <<"\n";}
}
