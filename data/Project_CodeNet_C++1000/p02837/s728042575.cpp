#include<bits/stdc++.h>
using namespace std;
typedef long long int INT;

int main()
{
    int n;
    cin>>n;
    vector<int> A(n);
    vector<vector <int>> x(n);
    vector<vector <int>> y(n);
    for (int i=0; i<n;i++){
        cin>>A.at(i);
        for (int j=0;j<A[i];++j){
            int tempx,tempy;
            cin>>tempx>>tempy;
            tempx-=1;
            x.at(i).push_back(tempx);
            y.at(i).push_back(tempy);
        }
    }
    int ans=0;

    for (int i=0;i<(1<<n);++i){
        int cnt=0;
        bool ok=true;
        for (int j=0;j<n;j++){    
            if((i>>j)%2==0){
                continue;
            }
            else{
                cnt++;
                for (int k=0;k<A.at(j);k++){
                    if(y[j][k]==1){
                        if((i>>x[j][k])%2==0) {
                            ok=false;
                        }  
                    }
                    else if(y[j][k]==0){
                        if((i>>x[j][k])%2==1){
                            ok=false;
                        }
                    }
                }
            }
        }
        if(ok){
            ans=max(ans,cnt);
        }
    }
    cout<<ans<<endl;
}