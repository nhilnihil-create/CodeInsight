#include <bits/stdc++.h>
using namespace std;

int main() {
   int n,c=0;
    cin >> n;
    
       
       for(int i=1;i<=9;i++)
        {
            for(int j=1;j<=9;j++)
                {
                   if(n==(i*j))
                    { 
                        c=1;
                        break;
                    }
                }
                if(c==1)
                    {
                        break;
                    }
        }
                if(c==0)
                    {
                        cout << "No";
                    }
                    if(c==1)
                        {
                             cout << "Yes";
                        }
        
        return 0;
        
}