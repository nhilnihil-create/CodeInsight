
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using Vec = vector<int>;

int main() {
    
    int n,m,miss=0,ac=0;
    cin>>n>>m;
    Vec vec(n,0),wa(n,0);
    
    for(int i=0;i<m;i++){
        int a;
        string b;
        cin>>a>>b;

        if(b=="AC"){
            if(vec[a-1]==0){
                ac++;
                 vec[a-1]=1;
            }
        }

        else{
            if(vec[a-1]==0){
                wa[a-1]++;
            }
        }

    
        }
    
    for(int i=0;i<n;i++){
            if(vec[i]==1){
                miss+=wa[i];
            }
    }
    cout<<ac<<" "<<miss<<endl;
}
 