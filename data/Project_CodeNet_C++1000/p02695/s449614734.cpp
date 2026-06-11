#include<bits/stdc++.h>
using namespace std;
int n,m,q;
vector<int> a(100), b(100), c(100), d(100);
int ans = 0;

void dfs(vector<int> &A, int &num, int i){
    if(i == n){
        int sum = 0;
        for (int j = 0; j < q; j++)
        {
            if(A[b[j]] - A[a[j]] == c[j]) sum += d[j];
        }
        ans = max(ans, sum); 
    }
    else{
        for (int j = num; j < m; j++)
        {
            A.push_back(j);
            dfs(A,j,i+1);
            A.pop_back();
        }
    }
}
 

int main(){
    cin >> n >> m >> q;
    for (int i = 0; i < q; i++)
    {
        int x, y, z, w;
        cin >> x >> y >> z >> w;
        a[i] = x-1;
        b[i] = y-1;
        c[i] = z;
        d[i] = w;

    }
    vector<int> A = {};
    int num = 0;
    dfs(A, num, 0);
    cout << ans << endl;

}