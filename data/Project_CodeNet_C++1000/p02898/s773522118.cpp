#include <bits/stdc++.h> 
#include <iomanip>

using namespace std;
#define ll long long

ll INF = 1e18;

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    int n,t;
    cin>>n>>t;

    int cnt = 0;

    for(int i=0;i<n;i++)
    {
        int a; cin>>a;

        if(a>=t)
        cnt++;
    }

    cout<<cnt<<endl;
    return 0;
}
