#include<iostream>
#include<vector>
#define lli long long int
#include<climits>
#include<unordered_map>
#include<algorithm>
#include<bitset>
#include<map>
#include<cmath>
#include<queue>
#define pb push_back
#define N (int)(1e5)
using namespace std;
using namespace std;
int main()
{
    int h,n;
    int i,j;
    cin>>h>>n;
    vector<vector<lli>>dp(n,vector<lli>(h+1));
    vector<int>att(n);
    vector<int>pt(n);
    for(i=0;i<n;i++){ cin>>att[i];cin>>pt[i];}
    for(i=0,j=0;i<n;i++) dp[i][j]  = 0;
    vector<lli>mins(h+1);
    mins[0] = 0;
    
    for(j=1;j<=h;j++)
    {
        mins[j] = LLONG_MAX;
        for(i=0;i<n;i++)
        {
            if(j-att[i]>=0) dp[i][j] = pt[i] + mins[j-att[i]];
            else dp[i][j] = pt[i];
            
            if(dp[i][j]<mins[j])  mins[j] = dp[i][j];
        }
        
    }
    
    
//    for(int i=0;i<n;i++)
//    {
//        for(int j=0;j<=h;j++)
//        {
//            cout<<dp[i][j]<<" ";
//
//        }
//        cout<<endl;
//    }
//
    
    
    
    cout<<mins[h]<<endl;
    
    
    
    

}

