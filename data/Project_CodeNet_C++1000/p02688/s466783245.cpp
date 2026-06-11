#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k;cin>>n>>k;
    bool visited[n+1];
    memset(visited,0,sizeof(visited));
    for(int i=0;i<k;i++){
        int d;cin>>d;
        for(int j=0;j<d;j++){
            int x;cin>>x;
            if(!visited[x]){
                visited[x]=true;
                n--;
            }
        }
    }
    cout <<n<<endl;
}
