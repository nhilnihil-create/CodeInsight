#include <iostream>
#include <cmath>
#include <stdint.h>
#include <iomanip>
#include <vector>
#include<algorithm>
#include <queue>
using namespace std;
 
#define int long long
#define INF 1001001001

int arr[200001];
 
int nChoosek( int n, int k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    int result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}

int choose2(int n){
	
	return n*(n-1)/2;
}

int32_t main() {
	
   string s;
   
   cin >> s;
   
   int q;
   
   cin >> q;
   int cnt = 0;
   for(int i=0;i<q;i++){
   	
   		int t;
   		
   		cin >> t;
   		
   		if(t==1){
   			cnt++;
		}
   		else if(t==2){
   			
   			int f;
   			cin >> f;
   			
   			if(f==1){
   				string c;
   				cin >> c;
   				if(cnt%2 ==0){
   					s.insert(0,c);
				}
				else{
   					s.insert(s.length(),c);
   				}
			}
   			else{
   				string p;
   				cin >> p;
   				if(cnt%2 ==1){
   					s.insert(0,p);
   				}
   				else{
   						s.insert(s.length(),p);
				   }
			}
   			
		}
   }
   if(cnt%2==1){
		reverse(s.begin(), s.end());
   }
 	cout << s << endl;
}