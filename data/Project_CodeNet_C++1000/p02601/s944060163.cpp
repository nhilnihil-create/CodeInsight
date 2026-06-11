#pragma GCC optimize("Ofast")
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

const long long INFL = 1e17+7;
const long long INFI = 1e9+7;
const long long MOD = 1e9+7;
const double EPS = 1e-8;
const double PI=acos(-1);

using namespace std;


int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	long long a,b,c;
    cin >> a >> b >> c;
    int k;
    cin >> k;
  
    for(int i=0;i<k;i++){
      c*=2;
      if(c>b && b>a){
        cout << "Yes" << endl;
        return 0;
      }
    }
  
    for(int i=0;i<k;i++){
        c/=2;
        b*=2;
        if(c>b && b>a){
          cout << "Yes" << endl;
          return 0;
        }
    }
  
    cout << "No" << endl;
  
	return 0;
}
