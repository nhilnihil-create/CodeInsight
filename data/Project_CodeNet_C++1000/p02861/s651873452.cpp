#include<bits/stdc++.h>
using namespace std;
int n;
double L[10][10];
float total = 0;
void dfs (vector<bool> visited,float sum,int i){
    bool all_visited = true;
    for (int j = 0; j < n; j++)
    {
        if(!visited[j]) all_visited = false;
    }
    
    if(all_visited) total += sum;
    else{
        visited[i] = true;
        for (int j = 0; j < n; j++)
        {
            if(!visited[j]){
                sum += L[i][j];
                dfs(visited,sum,j);
            }
        }
        
    }
}
int main(){
    cin >>  n;
    vector<int> x(n),y(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i] ;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            L[i][j] = L[j][i] = sqrt((x[i] - x[j])*(x[i] - x[j])+(y[i] - y[j])*(y[i] - y[j]));
        }
        
    }
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i != j)
            sum += L[i][j];
        }
    }
    cout << fixed<<setprecision(10)<< sum/n << endl;
    
    
    
    

}