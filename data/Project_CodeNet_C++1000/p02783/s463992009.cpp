#include<bits/stdc++.h>
#define boost  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int 
using namespace std;
void sol(){
  	int h,a;
  	cin >> h >> a;
  	int attack=0;
  		for(int i=0;i<=10000;i++){
  			h-=a;
  			attack++;
  			if(h<=0){
  				break;
  			}
  		}
  		cout << attack;
 	}


int main()
{
	boost;
	sol();
}