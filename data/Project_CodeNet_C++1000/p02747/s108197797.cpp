#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
int main()
{
    string s;
    cin >> s;
    
    int n = s.size() , flag = 0;
    
    string c = "hi" ; 
    
    int k = 0;
    if(n%2 == 0)
    {
        
        while(k<n)
        {
            if(s[k] != c[0] || s[k+1] != c[1])
            {
                cout << "No" << endl;
                return 0;
            }
            
            k+=2;
            if(k==n-1) break;
        }
    
    }
    
    else 
    {   
        cout << "No" << endl;
        return 0;
    }
    
    cout << "Yes" << endl; 
    
    
    return 0;
}