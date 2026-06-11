#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=10;
int n,m,k;
bool visited[N][N],visrow[N],viscol[N];
char arr[N][N];


bool counter(){
    int sum=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (arr[i][j]=='#' && !visrow[i] && !viscol[j]){
                sum++;
            }
        }
    }
    return sum==k;
}

int solve1(int ind){
    if (ind==n)
        return counter();
    int ret=0;
    visrow[ind]=true;
    ret+=solve1(ind+1);
    visrow[ind]=false;
    ret+=solve1(ind+1);
    return ret;
}

int solve(int ind){
    if (ind==m)
        return solve1(0);
    int ret=0;
    viscol[ind]=true;
    ret+=solve(ind+1);
    viscol[ind]=false;
    ret+=solve(ind+1);
    return ret;
}

int main()
{
    cin>>n>>m>>k;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++)
            cin>>arr[i][j];
    }
    cout<<solve(0);

    return 0;
}
