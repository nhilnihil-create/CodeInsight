#include<bits/stdc++.h>
#define PI 3.141592653589793238462
using namespace std;
typedef long long ll;
typedef long double db;
int a[105],b[105];
int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=1;i+2<=n;i++){
        if(a[i]==b[i]&&a[i+1]==b[i+1]&&a[i+2]==b[i+2]){
            cout<<"Yes"<<endl;return 0;
        }
    }
    cout<<"No"<<endl;
}