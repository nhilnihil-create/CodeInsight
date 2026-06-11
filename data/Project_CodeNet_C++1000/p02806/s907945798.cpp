#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n;
    while(cin>>n){
        string s[n],x;
        int sum=0,time[n];
        for(int i=0;i<n;i++){
            cin>>s[i]>>time[i];
        }
        cin>>x;
        int flag=0;
        for(int i=0;i<n;i++){
            if(flag!=1){
                if(s[i]==x)flag=1;
            }
            else if(flag==1){
                sum+=time[i];
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
