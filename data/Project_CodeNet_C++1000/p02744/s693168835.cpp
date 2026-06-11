#include <bits/stdc++.h>
using namespace std;

int n ;
void dfs_list(int c,string s,int premax){
    if(c==0){
        cout << s <<endl; ;
        return ;
    }
    else{
        for(int i=1;i<=premax+1;i++){
            dfs_list(c-1,s+(char)('a'+i-1),max(premax,i)) ;
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n ;
    dfs_list(n-1,"a",1) ;
    return 0;
}

