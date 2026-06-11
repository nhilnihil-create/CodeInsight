#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m,x;
cin>>n>>m>>x;
vector<int> kane(n);
vector<vector<int>> cot(m,vector<int>(n));
long int ans=1e18;
for (int i = 0; i < n; i++)
{
    cin>>kane.at(i);
for (int j = 0; j < m; j++)
{
    cin>>cot.at(j).at(i);
  
}

}
 


    bool exist = false;
    for (int bit = 0; bit < (1<<n); ++bit)
    {
int count=0;
int money=0;
        vector<int> sum(m);
        for (int i = 0; i < n; ++i) {
            if (bit & (1<<i)) {
            money+=kane.at(i);
                for (int j = 0; j < m; j++)
                {
                     sum.at(j) += cot.at(j).at(i);



                }
                
               
            }
        }

    
        for (int i = 0; i < m; i++)
        {
           
            
            if (sum.at(i) >= x) {count++; }
        }
        if (count==m)
        {
          
           if (ans>money)
           {
               ans=money;
           }
           
        }
        
        
    }
if (ans==1e18)
{
    cout << -1<< endl;
}
else
{
    cout<<ans<<endl;
}

 
}