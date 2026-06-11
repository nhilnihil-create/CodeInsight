#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    vector<vector<int> > matrix(10+1,vector<int>(10+1,0));
 
    int n;
    cin>> n;
    for(int i = 1; i <= n; i++)
    {
        matrix[to_string(i)[0]-'0'][i % 10]++;
    }
 
    long long int ans = 0;
    for(int i = 1; i < 10; i++)
        for(int j = 1; j < 10; j++)
         ans += (matrix[i][j] * matrix[j][i]);
 
 
    cout<<ans;
 
}