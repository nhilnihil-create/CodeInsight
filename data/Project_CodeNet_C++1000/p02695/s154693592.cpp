#include <bits/stdc++.h>
using namespace std;

int n , m , q;

int f(int x , int i , vector<int>& ans , vector<vector<int>>& qr){
    if(i == n){
    	int val = 0 ;
        for(auto i : qr){
        	int ai = i[0] , bi = i[1] , ci = i[2] , di = i[3] ;
        		if(ans[bi-1] - ans[ai-1] == ci){
        			val += di ;		
        		}
        }
        return val ;
    }
    int mx = 0 ;
    for(int j = x ; j <= m ; j++){
    	ans.push_back(j) ;
        mx = max(mx , f(j,i+1,ans,qr)) ;
        ans.pop_back() ;
    }
    return mx ;
}

int main()
{
    cin >> n >> m >> q ;
    vector<vector<int>> qr(q,vector<int>(4)) ;
    for(int i = 0 ; i < q ; i++){
    	for(int j = 0 ; j < 4 ; j++) cin >> qr[i][j] ;
    }
    vector<int> ans ;
    cout << f(1,0,ans,qr) ;
    return 0;
}