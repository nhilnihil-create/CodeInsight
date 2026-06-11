#include <bits/stdc++.h>
using namespace std ;
typedef long long ll;

int main(){
    int n,m;cin>>n>>m;
    vector<vector<int>> a(m);
    int count=0;
    for(int i=0;i<n;i++){
        int c,d;cin>>c>>d;
        if(c>m)continue;
        a[m-c].push_back(d);
        count++;
        //m-c日以前にやるしかない仕事
    }
    priority_queue<int> money;
    int sum=0;


    for(int i=m-1;i>=0;i--){
        for(int j:a[i]){
            money.push(j);
        }
        if(!money.empty()){
            sum+=money.top();
            money.pop();
        }
    }
    
    cout <<sum;
    
}