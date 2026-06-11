#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()    
{
    int n;
    cin>>n;
    map<int,int> m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        m[x] = i;
    }

    for(auto it = m.begin(); it != m.end(); ++it){
        cout<<it->second<<" ";
    }
}