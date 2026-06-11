#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <cmath>
#include <queue>
#include <map>
using namespace std;

int64_t mod = 998244353 ;

vector<int> getprime(int n){
    vector<int> p(0) ;
    vector<bool> table(n+1,0) ;
    for (int i = 2; i <= n; i++)
    {
        if (table.at(i) == 0)
        {
            p.push_back(i) ;
            for (size_t j = 2; j < n/i ; j++)
            {
                table.at(i*j) = 1 ;
            }
            
        }
        
    }
    return p ;
}

int main(){
    int n ;
    cin >> n ;
    vector<vector<int> > list(n,vector<int>(0));
    int a,b ;
    vector<int> edge(n-1) ;
    for (int i = 0; i < n-1; i++)
    {
        cin >> a >> b ;
        edge.at(i) = b-1 ;
        list.at(a-1).push_back(b-1) ;
    }
    int ans = 0 ;
    vector<int> color(n) ;
    color.at(0) = 0 ;
    queue<int> wait ;
    int child,parent ;
    wait.push(0) ;
    while (!(wait.empty()))
    {
        parent = wait.front() ;
        wait.pop() ;
        int num = 1 ;
        for (int i = 0; i < list.at(parent).size(); i++)
        {
            child = list.at(parent).at(i) ;
            if (num == color.at(parent))
            {
                num ++ ;
            }
            color.at(child) = num ;
            ans = max (ans,num) ;
            wait.push(child) ;
            num ++ ;
        }
        
    }
    cout << ans << endl ;
    for (int i = 0; i < n-1; i++)
    {
        cout << color.at(edge.at(i)) << endl ;
    }
    
    
    
}