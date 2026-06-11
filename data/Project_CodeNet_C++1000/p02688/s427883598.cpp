#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

main(){
    int n,k;
    cin>>n>>k;
    int check[101] = {0};
    int d,temp;
    for(int i=0;i<k;i++){
        cin>>d;
        while(d--){
            cin>>temp;
            check[temp] = 1;
        }
    }
    int count=0;
    for(int i=1;i<=n;i++){
        if(!check[i]) count++;
    }
    cout<<count;
}