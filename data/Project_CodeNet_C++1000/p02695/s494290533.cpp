#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, q;
int ans = 0;
vector<int> a, b, c, d;

void dfs(int l, vector<int> arr){
    if(arr.size() == n){

        //printf("\nA: ");
        //for(auto e : arr) printf("%d ", e);
        //printf("\n");

        int sum = 0;
        for(int j = 0; j < q; j++){
            if(arr[b[j]-1] - arr[a[j]-1] == c[j]){
                sum += d[j];
                
                //printf("A[%d] - A[%d] = %d, c[%d] = %d, d[%d] = %d\n",
                //    b[j]-1, a[j]-1, arr[b[j]-1] - arr[a[j]-1], j, c[j], j, d[j]);
                //printf("sum = %d\n", sum);
            }
        }
        ans = max(ans, sum);
    } else {
        for(int j = l; j <= m; j++){
            arr.push_back(j);
            dfs(j, arr);
            arr.pop_back();
        }
    }
}

int main(){
    cin >> n >> m >> q;
    a.resize(q);
    b.resize(q);
    c.resize(q);
    d.resize(q);
    for(int i = 0; i < q; i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    vector<int> arr;
    dfs(1, arr);
    cout << ans << endl;
    return 0;
}