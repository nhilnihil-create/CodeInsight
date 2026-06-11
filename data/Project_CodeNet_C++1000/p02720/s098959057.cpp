#include<bits/stdc++.h>
using namespace std;
int k,i= -1;
vector<long long> vec = {};
void dfs(long long x,int a){
    vec.push_back(x);
    if(x > 1000000000000) return;
    if(x == 0){
        for (int j = 1; j < 10; j++)
        {
            dfs(j,j);
        }
    }
    else{
        if(a != 0 && a!= 9){
            dfs(10*x + a-1,a-1);
            dfs(10*x + a,a);
            dfs(10*x + a+1,a+1);
        }
        if(a == 0) {
            dfs(10*x + 0,0);
            dfs(10*x + 1,1);
        }
        if(a == 9) {
            dfs(10*x + 8,8);
            dfs(10*x + 9,9);
        }
    }
}

int main(){
    cin >> k;
    dfs(0,0);
    sort(vec.begin(),vec.end());
    cout << vec[k] << endl;
}
