#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)

using namespace std;
const int IINF = INT_MAX;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000000000
int main(){
    int n,k; cin >> n >> k;
    
    int ans = 0;
    int ten = 1;
    while(true){
    	if(n < k){
    		break;
    	} else{
    		n/=k;
    		ten++;
    	}
    }
    
    cout << ten << endl;
    return 0;	
}