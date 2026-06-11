#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <sstream>
#include <numeric>
#include <stack>
#include <sstream>
#include <set>
using namespace std;

int64_t min(int64_t a,int64_t b) {
    if (a > b)
    {
        return b ;
    }else
    {
        return a ;
    }
}


int main(){
    int n,m ;
    cin >> n >> m ;
    vector<char> s(n+1) ;
    for (size_t i = 0; i < n+1; i++)
    {
        cin >> s.at(i) ;
    }
    stack<int> deme ;
    int now = n ;
    while(1){
        for (size_t i = 0; i < m; i++)
        {
            if (now >= m-i)
            {
                
                if (s.at(now-m+i) == '0')
                {
                    now -= m-i ;
                    deme.push(m-i) ;
                    break ;
                }else if (i == m-1)
                {
                    cout << -1 << endl ;
                    return 0 ;
                }
            
            }
        }
        if (now == 0)
        {
            break ;
        }
        
    }
    cout << deme.top() ;
    deme.pop() ;
    while (deme.empty() == 0)
    {
        cout << " " << deme.top() ;
        deme.pop() ;
    }
    cout << endl ;
    
}
