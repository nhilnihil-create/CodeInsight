#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <tuple>
#include <cmath>
#include <cstdio>
#include <cassert>
#include <functional>
#define _LIBCPP_DEBUG 0
using namespace std;


int main(void){
    int n,d;
    cin >> n >> d;

    vector<vector <int> > x(n,vector<int> (d));
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < d; j++)
        {
            cin >> x.at(i).at(j);
        }
    }

    int ans=0;
    for (int i = 0; i < n-1; i++)
    {   
        
        for (int j = i+1; j < n; j++)
        {   
            int in=0;
            for (int k = 0; k < d; k++)
            {
                in += (x.at(i).at(k) - x.at(j).at(k)) * (x.at(i).at(k) - x.at(j).at(k));
            }
            for (int k = 1; k <= sqrt(in); k++)
            {
                if (k*k==in)
                {
                    ans++;
                }
                
            }
            
            
        }
        
    }
    
    cout << ans << endl;
}
